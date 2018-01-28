//
// Created by Jasf on 28.01.2018.
//

#ifndef HORO_PREDICTIONSCREENJAVA_H
#define HORO_PREDICTIONSCREENJAVA_H

#include "base/horobase.h"
#include "managers/viewmodelsimpl/viewmodels.h"
#include "viewmodels/predictionscreenviewmodel/predictionscreenviewmodel.h"
#include "viewmodels/viewmodeldelegate.h"

namespace horo {

    class PredictionScreenViewModelDelegateImpl : public ViewModelDelegate {
    public:
        PredictionScreenViewModelDelegateImpl(strong<PredictionScreenViewModel> viewModel);
        virtual ~PredictionScreenViewModelDelegateImpl();

    public:
        void willAppear() override;
        void didAppear() override;
        void willDisappear() override;
        void didDisappear() override;

    public:
        inline void setActivity(jobject aObject) { activity_ = aObject; }
        inline jobject activity() const { return activity_; }

    private:
        strong<PredictionScreenViewModel> viewModel_;
        jobject activity_;
    };

};

#endif //HORO_PREDICTIONSCREENJAVA_H
