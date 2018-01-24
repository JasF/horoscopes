//
//  notificationsimpl.h
//  Horoscopes
//
//  Created by Jasf on 22.12.2017.
//  Copyright © 2017 Mail.Ru. All rights reserved.
//

#ifndef notificationsimpl_h
#define notificationsimpl_h

#include "managers/notifications/notifications.h"
#include "models/corecomponents/corecomponents.h"
#include "managers/settings/settings.h"
#include "managers/serializer/serializer.h"
#include "managers/notificationcenter/notificationcenter.h"
#include "managers/screensmanager/screensmanager.h"

namespace horo {
    
class NotificationsImpl : public Notifications {
public:
    static void setPrivateInstance(Notifications *instance);
public:
    NotificationsImpl(strong<CoreComponents> components,
                      strong<Settings> settings,
                      strong<Serializer> serializer,
                      strong<NotificationCenter> notificationCenter,
                      strong<ScreensManager> screensManager);
    ~NotificationsImpl() override;
    void initialize() override;
    void openSettings() override;
    bool isRegisteredForRemoteNotifications() override;
    string deviceToken() override;
    // for AppDelegate
    void didReceiveRemoteNotification(Json::Value userInfo) override;
    void didRegisterForRemoteNotificationsWithDeviceToken(string token) override;
    void didFailToRegisterForRemoteNotificationsWithError(error err) override;
    int pushTime() override;
    void setPushTime(int pushTime) override;
    void sendSettingsIfNeeded() override;
    void sendSettingsForZodiacName(string zodiacName) override;
    bool notificationsDisabled() override;
    void setNotificationsDisabled(bool disabled) override;
    void cleanBadgeNumber() override;
    
public: // NotificationsImplDelegate
    void handleReceivedRemoteNotification(dictionary userInfo) override;
    
private:
    string generatePushSettingsString();
    void sendSettings();
    
private:
    strong<CoreComponents> components_;
    strong<Settings> settings_;
    strong<Serializer> serializer_;
    strong<NotificationCenter> notificationCenter_;
    strong<ScreensManager> screensManager_;
};
    
}

#endif /* notificationsimpl_h */
