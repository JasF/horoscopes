//
//  friendsscreenmodel.h
//  Horoscopes
//
//  Created by Jasf on 29.10.2017.
//  Copyright © 2017 Mail.Ru. All rights reserved.
//

#ifndef friendsscreenmodel_h
#define friendsscreenmodel_h

#include "base/horobase.h"
#include "data/person.h"

namespace horo {
  
    enum CancelTypes {
        CancelAllFriendsLoad,
        CancelFriendBirthdayLoad
    };
    
    class _FriendsScreenModel {
    public:
        virtual ~_FriendsScreenModel() {}
        
    public:
        virtual void updateFriendsFromFacebook() = 0;
        virtual bool webViewDidLoad(std::string url) = 0;
        virtual list<strong<Person>> allFriends() = 0;
        virtual void cancelOperation(enum CancelTypes type) = 0;
        virtual void personSelected(strong<Person> person) = 0;
        
    public:
        function<void(string url, vector<string> allowedPatterns)> authorizationUrlCallback_ = nullptr;
        function<void(set<strong<Person>> friends)> friendsUpdatedCallback_ = nullptr;
        function<void(strong<Person> person)> personStateChangedCallback_ = nullptr;
        function<void(strong<Person> person, bool closeAlert)> serialRequestAlertViewControllerCallback_ = nullptr;
        function<void *()> webViewControllerUICalback_ = nullptr;
    };
    
    typedef reff<_FriendsScreenModel> FriendsScreenModel;
};

#endif /* friendsscreenmodel_h */
