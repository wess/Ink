//
//  InkHTMLAttributes.h
//  Ink
//
//  Created by Wess Cope on 5/6/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InkAttributes.h"

@interface InkHTMLAttributes : NSObject
@property (readonly, nonatomic) InkHeaderAttributesBlock  headerAttributes;
@property (readonly, nonatomic) InkAttributesBlock        paragraphAttributes;
@end
