//
//  notifications.h
//  Horoscopes
//
//  Created by Jasf on 22.12.2017.
//  Copyright © 2017 Mail.Ru. All rights reserved.
//

#ifndef notifications_h
#define notifications_h

#include "base/horobase.h"

namespace horo {
    class NotificationsImpl;
    class _Notifications {
        friend class NotificationsImpl;
    public:
        virtual ~_Notifications(){}
        virtual void initialize()=0;
        virtual void openSettings()=0;
        virtual bool isRegisteredForRemoteNotifications()=0;
        virtual string deviceToken()=0;
        // forward internal methods for AppDelegate
        virtual void didReceiveRemoteNotification(Json::Value userInfo)=0;
        virtual void didRegisterForRemoteNotificationsWithDeviceToken(string token)=0;
        virtual void didFailToRegisterForRemoteNotificationsWithError(error err)=0;
        virtual int pushTime()=0;
        virtual void setPushTime(int pushTime)=0;
        virtual void sendSettingsIfNeeded()=0;
        virtual bool notificationsDisabled()=0;
        virtual void setNotificationsDisabled(bool disabled)=0;
        virtual void cleanBadgeNumber()=0;
// private methods
        virtual void sendSettingsForZodiacName(string zodiacName)=0;
        virtual void handleReceivedRemoteNotification(dictionary userInfo) {}
    };
    typedef reff<_Notifications> Notifications;
};


#endif /* notifications_h */
