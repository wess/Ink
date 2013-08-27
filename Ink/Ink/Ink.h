//
//  Ink.h
//  Ink
//
//  Created by Wess Cope on 5/2/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UITextView+Ink.h"

@interface Ink : NSObject
- (instancetype)initWithRenderer:(Class)rendererClass;
- (NSAttributedString *)renderFromString:(NSString *)string;
@end
 