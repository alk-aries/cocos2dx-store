/*
 Copyright (C) 2012-2014 Soomla Inc.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

// Created by Igor Yegoroff on 5/17/13.

#ifndef __CCPurchaseType__
#define __CCPurchaseType__

#include "cocos2d.h"
#include "CCError.h"

namespace soomla {
	/** 
     @class CCPurchaseType
     @brief A way to purchase a PurchasableVirtualItem.
     
     A `CCPurchaseType` is a way to purchase a `CCPurchasableVirtualItem`. This
     abstract class describes basic features of the actual implementations of
     `CCPurchaseType`.
	 */
    class CCPurchaseType : public cocos2d::Ref {
        // 26.11.14 - this is done through ID instead of actual object, since
        // macro needs an object inheriting from `Ref`, which we cannot forward
        // declare. Including `CCPurchasableVirtualItem.h` causes circular dependency
        CC_SYNTHESIZE_RETAIN(cocos2d::__String *, mAssociatedItemId, AssociatedItemId);
    public:
        CCPurchaseType() {}
        
        virtual bool init();
        
        /**
         Buys the purchasable virtual item.
         Implementation in subclasses will be according to specific type of 
         purchase.
         
         @param payload string you want to be assigned to the purchase. This
         string is saved in a static variable and will be given bacl to you when 
         the purchase is completed.
         @param error A `CCError` for error checking.
         */
        virtual void buy(const char* payload, CCError **error = NULL) = 0;
      
        virtual ~CCPurchaseType();
    };
    
}

#endif // __CCPurchaseType__
