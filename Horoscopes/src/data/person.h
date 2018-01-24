//
//  person.h
//  Horoscopes
//
//  Created by Jasf on 29.10.2017.
//  Copyright © 2017 Mail.Ru. All rights reserved.
//

#ifndef person_h
#define person_h

#include "base/horobase.h"
#include "zodiac.h"
#include "base/coding.h"
#include "data/datewrapper.h"

namespace horo {
    enum Gender {
        GenderUnknown,
        Male,
        Female
    };
    enum PersonStatus {
        StatusUnknown,
        StatusReadyForRequest,
        StatusCompleted,
        StatusFailed
    };
    enum PersonType {
        TypeUnknown,
        TypeUser,
        TypeFriend
    };
    class _Person : public Coding {
    public:
        _Person();
        _Person(strong<Zodiac> zodiac,
                std::string name,
                std::string imageUrl,
                std::string personUrl,
                Gender gender,
                PersonStatus status,
                PersonType type,
                DateWrapper birthdayDate,
                bool withFacebook);
        virtual ~_Person();
    public:
        void encode(Json::Value &coder) override;
        void decode(Json::Value &coder) override;
        strong<Zodiac> zodiac() { return zodiac_; }
        inline bool withFacebook() const { return withFacebook_; }
        inline void setWithFacebook(bool a) { withFacebook_ = a; }
        string uniqueIdentifier();
        string name() const { return name_; }
        DateWrapper birthdayDate() const { return birthdayDate_; }
        void setBirthdayDate(DateWrapper date);
        PersonStatus status() const { return status_; }
        void setPersonStatus(PersonStatus status) { status_ = status; }
        PersonType type() const { return type_; }
        Gender gender() const { return gender_; }
        string imageUrl() const { return imageUrl_; }
        string personUrl() const { return personUrl_; }
        void setZodiac(strong<Zodiac> zodiac) { zodiac_ = zodiac; }
        bool updating() const { return updating_; }
        void setUpdating(bool updating) { updating_ = updating; }
        void *wrapper() { return wrapper_; }
        void setWrapper(void *wrapper) { wrapper_ = wrapper; }
        void logout();
    private:
        std::string name_; // utf-8§
        std::string imageUrl_;
        std::string personUrl_;
        strong<Zodiac> zodiac_;
        Gender gender_;
        PersonStatus status_;
        PersonType type_;
        DateWrapper birthdayDate_;
        bool withFacebook_;
        bool updating_;
        void *wrapper_;
    };
    
    typedef reff<_Person> Person;
};

#endif /* person_h */
