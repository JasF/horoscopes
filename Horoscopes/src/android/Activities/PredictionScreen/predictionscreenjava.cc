//
// Created by Jasf on 27.01.2018.
//

#include "android/Activities/PredictionScreen/predictionscreenjava.h"

namespace horo {
    strong<LocalRef> g_activityReference = nullptr;

    static PredictionScreenViewModelDelegateImpl *g_sharedInstance = nullptr;
    PredictionScreenViewModelDelegateImpl::PredictionScreenViewModelDelegateImpl(strong<PredictionScreenViewModel> viewModel) : viewModel_(viewModel) {
        g_sharedInstance = this;
        SCParameterAssert(viewModel.get());
        viewModel->setDataFetchedCallback([this](bool success){
            int i=0;
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

    g_activityReference = new LocalRef(aThis);
    // g_sharedInstance->setActivity(env->NewGlobalRef())
}
