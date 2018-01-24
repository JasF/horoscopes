//
//  helloscreenviewmodelimpl.h
//  Horoscopes
//
//  Created by Jasf on 29.10.2017.
//  Copyright © 2017 Mail.Ru. All rights reserved.
//

#ifndef helloscreenviewmodelimpl_h
#define helloscreenviewmodelimpl_h

#include "helloscreenviewmodel.h"
#include "models/helloscreenmodel/helloscreenmodel.h"
#include "managers/screensmanager/screensmanager.h"

namespace horo {
  
    class HelloScreenViewModelImpl : public HelloScreenViewModel {
    public:
        HelloScreenViewModelImpl(strong<HelloScreenModel> model, strong<ScreensManager> screensManager);
        ~HelloScreenViewModelImpl() override;
        
    public:
        void continueTapped(DateWrapper date) override;
        void loggedInOverFacebook() override;
        void setUserLoggedInCallback(std::function<void(bool success)> a) override;
        string zodiacNameWithDate(DateWrapper date) override;
        
    private:
        strong<HelloScreenModel> model_;
        strong<ScreensManager> screensManager_;
        std::function<void(bool success)> userLoggedInCallback_;
    };
};

#endif /* helloscreenviewmodelimpl_h */
