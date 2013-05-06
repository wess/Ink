//
//  InkRenderProtocol.h
//  Ink
//
//  Created by Wess Cope on 5/6/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol InkRenderProtocol <NSObject>
- (NSAttributedString *)renderFromString:(NSString *)string;
@end
