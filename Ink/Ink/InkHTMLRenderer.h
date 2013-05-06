//
//  InkHTMLRenderer.h
//  Ink
//
//  Created by Wess Cope on 5/6/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InkRenderProtocol.h"
#import "InkHTMLAttributes.h"
#import "InkStringBuilder.h"

@interface InkHTMLRenderer : NSObject<InkRenderProtocol>
@property (strong, nonatomic) NSMutableArray    *elements;
@property (strong, nonatomic) InkHTMLAttributes *attributes;
@property (strong, nonatomic) InkStringBuilder  *stringBuilder;

- (NSAttributedString *)renderFromString:(NSString *)string;
@end
