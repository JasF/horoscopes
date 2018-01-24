//
//  viewmodelsimpl.h
//  Horoscopes
//
//  Created by Jasf on 28.10.2017.
//  Copyright © 2017 Mail.Ru. All rights reserved.
//

#ifndef viewmodelsimpl_h
#define viewmodelsimpl_h

#include "viewmodels.h"
#include "models.h"
#include "managers/screensmanager/screensmanager.h"
#include "managers/themesmanager/themesmanager.h"

namespace horo {
    
    class ViewModelsImpl : public ViewModels {
    public:
        ViewModelsImpl(strong<Models> models, strong<ThemesManager> themesManager);
        ~ViewModelsImpl() override;
        
        void setScreensManager(strong<ScreensManager> screensManager) { screensManager_ = screensManager; }
        
    public:
        strong<PredictionScreenViewModel> predictionScreenViewModel() override;
        strong<PredictionScreenViewModel> predictionScreenViewModel(strong<Person> person, strong<Zodiac> zodiac) override;
        strong<HelloScreenViewModel> helloScreenViewModel() override;
        strong<MenuScreenViewModel> menuScreenViewModel() override;
        strong<FriendsScreenViewModel> friendsScreenViewModel() override;
        strong<AccountScreenViewModel> accountScreenViewModel() override;
        strong<NotificationsScreenViewModel> notificationsScreenViewModel() override;
        strong<PushTimeScreenViewModel> pushTimeScreenViewModel() override;
        
    private:
        strong<Models> models_;
        strong<ScreensManager> screensManager_;
        strong<ThemesManager> themesManager_;
    };
    
};

#endif /* viewmodelsimpl_h */
