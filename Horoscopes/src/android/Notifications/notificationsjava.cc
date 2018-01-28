//
// Created by Jasf on 28.01.2018.
//

#include "notificationsjava.h"
#include "managers/managers.h"
#include "managers/settings/settings.h"
#include "managers/notifications/notificationsimpl.h"

namespace horo {

    class NotificationsJava : public Notifications {
    public:
        static NotificationsJava *shared() {
            static NotificationsJava *sharedInstance = nullptr;
            if (!sharedInstance) {
                sharedInstance = new NotificationsJava(Managers::shared().settings());
            }
            return sharedInstance;
        }
    public:
        NotificationsJava(strong<Settings> settings) : settings_(settings) {
            SCParameterAssert(settings_.get());
        }
        ~NotificationsJava() override {

        }
    public:

         void initialize() override {}
         void openSettings() override {}
         bool isRegisteredForRemoteNotifications() override {return false;}
         string deviceToken() override {return "";}
        // forward internal methods for AppDelegate
         void didReceiveRemoteNotification(Json::Value userInfo) override {}
         void didRegisterForRemoteNotificationsWithDeviceToken(string token) override {}
         void didFailToRegisterForRemoteNotificationsWithError(error err) override {}
         int pushTime() override { return 0; }
         void setPushTime(int pushTime) override {}
         void sendSettingsIfNeeded() override {}
         bool notificationsDisabled() override { return true; }
         void setNotificationsDisabled(bool disabled) override {}
         void cleanBadgeNumber() override {}
// private methods
         void sendSettingsForZodiacName(string zodiacName) override {}
         void handleReceivedRemoteNotification(dictionary userInfo) override {}

    private:
        strong<Settings> settings_;
    };

};

extern "C"
JNIEXPORT void
        JNICALL
Java_com_horoscopes_jasf_horoscopes_Notifications_setPrivateInstance(
        JNIEnv *env,
jobject aObject) {
    NotificationsImpl::setPrivateInstance(NotificationsJava::shared());
//
// FirestoreJavaImpl::shared()->setJObject(env->NewGlobalRef(aObject));
}
