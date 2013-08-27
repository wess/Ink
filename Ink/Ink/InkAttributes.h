//
//  InkAttributes.h
//  Ink
//
//  Created by Wess Cope on 5/3/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const InkLinkAttribute;

typedef NSDictionary *(^InkAttributesBlock)(NSString *text);
typedef NSDictionary *(^InkHeaderAttributesBlock)(NSString *text, NSInteger level);
typedef NSDictionary *(^InkLinkAttributesBlock)(NSURL *link, NSString *title, NSString *content);
typedef NSDictionary *(^InkCodeAttributesBlock)(NSString *language, NSString *text);

@interface InkAttributes : NSObject
@end
