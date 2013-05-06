//
//  InkHTMLElement.h
//  Ink
//
//  Created by Wess Cope on 5/6/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <libxml/HTMLparser.h>


@interface InkHTMLElement : NSObject
@property (readonly, nonatomic) InkHTMLElement  *parent;
@property (readonly, nonatomic) InkHTMLElement  *nextElement;
@property (readonly, nonatomic) InkHTMLElement  *previousElement;
@property (readonly, nonatomic) NSArray         *children;
@property (readonly, nonatomic) NSString        *className;
@property (readonly, nonatomic) NSString        *tag;
@property (readonly, nonatomic) NSString        *raw;
@property (readonly, nonatomic) NSDictionary    *attributes;
@property (readonly, nonatomic) NSString        *text;

+ (instancetype)inkHTMLElementWithNode:(xmlNode *)node;
- (id)initWithNode:(xmlNode *)node;
@end
