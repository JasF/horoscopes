//
// Created by Jasf on 27.01.2018.
//

#include "android/Activities/PredictionScreen/predictionscreenjava.h"
#include "managers/managers.h"
#include "data/person.h"
#include "data/zodiac.h"

namespace horo {
    static strong<GlobalObjectRef> g_activityReference;

    static PredictionScreenViewModelDelegateImpl *g_sharedInstance = nullptr;
    PredictionScreenViewModelDelegateImpl::PredictionScreenViewModelDelegateImpl(strong<PredictionScreenViewModel> viewModel) : viewModel_(viewModel) {
        g_sharedInstance = this;
        SCParameterAssert(viewModel.get());
        viewModel->setDataFetchedCallback([this](bool success){

            auto list = viewModel_->horoscopesText();
            string todayPrediction = *std::next(list.begin(), 1);

            static jmethodID setTodayTextMethod = nullptr;
            JNIEnv *env = getEnv();
            jclass cls = ClassesCache::shared()->classWithName("com/horoscopes/jasf/horoscopes/PredictionScreen");
            jthrowable mException = env->ExceptionOccurred();
            if (mException )
            {
                env->ExceptionDescribe();
                env->ExceptionClear();
            }
            if (cls) {
                setTodayTextMethod = env->GetMethodID(cls, "setTodayText", "(Ljava/lang/String;)V");
            }

            if (setTodayTextMethod) {
                jstring argument = env->NewStringUTF(todayPrediction.c_str());
                getEnv()->CallVoidMethod(g_activityReference->get(), setTodayTextMethod, argument);
            }

        });
        viewModel->didActivated();
    }

    PredictionScreenViewModelDelegateImpl::~PredictionScreenViewModelDelegateImpl() {
        if (g_sharedInstance == this) {
            g_sharedInstance = nullptr;
        }
    }

    void PredictionScreenViewModelDelegateImpl::willAppear() {

    }

    void PredictionScreenViewModelDelegateImpl::didAppear() {

    }

    void PredictionScreenViewModelDelegateImpl::willDisappear() {

    }

    void PredictionScreenViewModelDelegateImpl::didDisappear() {

    }

};

extern "C"
JNIEXPORT void
        JNICALL
Java_com_horoscopes_jasf_horoscopes_PredictionScreen_setPrivateInstance(
        JNIEnv *env, jobject aThis) {
    setEnv(env);

    g_activityReference = new GlobalObjectRef(aThis);
/*
    std::string name,
    std::string imageUrl,
    std::string personUrl,
    Gender gender,
    PersonStatus status,
    PersonType type,
    DateWrapper birthdayDate,
    bool withFacebook);
    */
    Managers::shared().coreComponents()->person_ = new Person(new Zodiac(Aquarius), "", "", "", GenderUnknown, StatusUnknown, TypeUnknown, DateWrapper(), false);
    Managers::shared().screensManager()->showPredictionViewController();
    // g_sharedInstance->setActivity(env->NewGlobalRef())
}
