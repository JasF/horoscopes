//
// Created by Jasf on 27.01.2018.
//

#include "managers/screensmanager/screensmanagerimpl.h"
#include "android/Activities/PredictionScreen/predictionscreenjava.h"
#include "managers/managers.h"

using namespace std;
using namespace horo;

    namespace horo {
        class ScreensManagerJava;
        static ScreensManagerJava *g_sharedInstance = nullptr;
        class ScreensManagerJava : public ScreensManager {
        public:
            static ScreensManagerJava *shared() {
                return g_sharedInstance;
            }

            ScreensManagerJava(strong<ScreensManager> original, jobject reference) : original_(original), impl_((ScreensManagerImpl *)original.get()), reference_(reference) {
                g_sharedInstance = nullptr;
            }
            ~ScreensManagerJava() override {}

        public:
            void showPredictionViewController(strong<Person> person, bool push = false) override {

                SCParameterAssert( !person.get() || (person.get() && person->zodiac().get()) );
                if (person.get() && !person->zodiac().get()) {
                    return;
                }
                showPredictionViewController(person, false, nullptr);
            }

            void showPredictionViewController(strong<Zodiac> zodiac) override {
                SCParameterAssert( zodiac.get() );
                showPredictionViewController(nullptr, false, zodiac);
            }

            void showPredictionViewController(strong<Person> person, bool push, strong<Zodiac> zodiac) {
                strong<PredictionScreenViewModel> viewModel = impl_->viewModels()->predictionScreenViewModel(person, zodiac);
                PredictionScreenViewModelDelegateImpl *impl = new PredictionScreenViewModelDelegateImpl(viewModel);
            }

            void showPredictionViewController() override {
                showPredictionViewController(Managers::shared().coreComponents()->person_);
            }

            void showWelcomeViewController() override {

            }
            void showMenuViewController(bool animated) override {

            }

            void showTableSearch() {

            }

            void showAccountViewController() override {

            }

            void showFriendsViewController() override {

            }

            void showFeedbackViewController() override {

            }

            void showNotificationsViewController() override {

            }

            void showPushTimeViewController() override {

            }

        private:
            strong<ScreensManager> original_;
            ScreensManagerImpl *impl_;
            jobject reference_;
        };
    };

extern "C"
JNIEXPORT void
        JNICALL
Java_com_horoscopes_jasf_horoscopes_ScreensManager_setPrivateInstance(
        JNIEnv *env,
jobject aObject) {
    setEnv(env);
    g_sharedInstance = new ScreensManagerJava(Managers::shared().screensManager(), env->NewGlobalRef(aObject));
    ScreensManagerImpl::setPrivateInstance(g_sharedInstance);
}
