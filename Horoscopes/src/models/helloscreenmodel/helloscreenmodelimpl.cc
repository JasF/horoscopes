//
//  helloscreenmodelimpl.c
//  Horoscopes
//
//  Created by Jasf on 29.10.2017.
//  Copyright © 2017 Freedom. All rights reserved.
//

#include "helloscreenmodelimpl.h"

namespace horo {
  
    HelloScreenModelImpl::HelloScreenModelImpl(strong<CoreComponents> components,
                                               strong<LoginManagerFactory> loginManagerFactory,
                                               strong<Settings> settings)
    : components_(components)
    , loginManagerFactory_(loginManagerFactory)
    , settings_(settings) {
        SCParameterAssert(components_.get());
        SCParameterAssert(loginManagerFactory_.get());
        SCParameterAssert(settings_.get());
    }
    
    HelloScreenModelImpl::~HelloScreenModelImpl() {
        
    }
    
    void HelloScreenModelImpl::handlePerson(strong<Person> person) {
        settings_->setCurrentPerson(person);
        components_->person_ = person;
        if (personGatheredCallback_) {
            personGatheredCallback_(true);
        }
    }
    
    void HelloScreenModelImpl::loginOnFacebook() {
        loginManager_ = loginManagerFactory_->createFacebookLoginManager();
        SCAssert(loginManager_.get(), "login manager is not allocated");
        if (!loginManager_.get()) {
            return;
        }
        loginManager_->requestUserInformation([this](strong<Person> person) {
            // set to application storage
            if (!person.get()) {
                if (personGatheredCallback_) {
                    personGatheredCallback_(false);
                }
                return;
            }
            handlePerson(person);
        });
    }
    
    void HelloScreenModelImpl::personRepresentation(function<void(std::string imageUrl, std::string name, horo::DateWrapper birthday)> callback) {
        strong<Person> person = components_->person_;
        if (!person.get()) {
            if (callback) {
                callback("", "", DateWrapper());
            }
            return;
        }
        if (callback) {
            callback(person->imageUrl(), person->name(), person->birthdayDate());
        }
    }
    
    void HelloScreenModelImpl::createPersonWithBirthdayDate(DateWrapper wrapper) {
        ZodiacTypes type = Zodiac::zodiacTypeByDate((Months)wrapper.month(), wrapper.day(), wrapper.year());
        strong<Zodiac> zodiac = new Zodiac(type);
        strong<Person> person = new Person(zodiac, "", "", "", Male, StatusUnknown, TypeUser, wrapper, false);
        handlePerson(person);
    }
};
