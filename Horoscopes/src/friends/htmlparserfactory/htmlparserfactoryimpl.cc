//
//  htmlparserfactoryimpl.c
//  Horoscopes
//
//  Created by Jasf on 06.11.2017.
//  Copyright © 2017 Mail.Ru. All rights reserved.
//

#include "htmlparserfactoryimpl.h"
#include "friends/htmlparser/facebook/facebookhomepageparser.h"
#include "friends/htmlparser/facebook/facebookuserinformationparser.h"
#include "friends/htmlparser/facebook/facebookfriendsparser.h"
#include "friends/htmlparser/facebook/facebookfriendinformationparser.h"
#include "friends/htmlparser/facebook/facebookuserdetailparser.h"

namespace horo {
    strong<HtmlParser> HtmlParserFactoryImpl::createFacebookHomePageParser(std::string text) {
        strong<FacebookHomePageParser> parser = new FacebookHomePageParser(text);
        return parser;
    }
    
    strong<HtmlParser> HtmlParserFactoryImpl::createFacebookUserInformationParser(std::string text) {
        strong<FacebookUserInformationParser> parser = new FacebookUserInformationParser(text);
        return parser;
    }
    
    strong<HtmlParser> HtmlParserFactoryImpl::createFacebookFriendsParser(std::string text) {
        strong<FacebookFriendsParser> parser = new FacebookFriendsParser(text);
        return parser;
    }
    
    strong<HtmlParser> HtmlParserFactoryImpl::createFacebookFriendInformationParser(std::string text) {
        strong<FacebookFriendInformationParser> parser = new FacebookFriendInformationParser(text);
        return parser;
    }
    
    strong<HtmlParser> HtmlParserFactoryImpl::createFacebookUserDetailParser(std::string text) {
        strong<FacebookUserDetailParser> parser = new FacebookUserDetailParser(text, birthdayDetector_);
        return parser;
    }
}
