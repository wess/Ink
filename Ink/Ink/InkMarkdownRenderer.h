//
//  InkMarkdownRenderer.h
//  Ink
//
//  Created by Wess Cope on 5/2/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InkRenderProtocol.h"

@interface InkMarkdownRenderer : NSObject<InkRenderProtocol>
- (NSAttributedString *)renderFromString:(NSString *)string;
@end
