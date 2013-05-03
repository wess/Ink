//
//  InkStringBuilder.h
//  Ink
//
//  Created by Jeremy Tregunna on 2013-05-03.
//  Copyright (c) 2013 Jeremy Tregunna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JInjector/JInjector.h>

@interface InkStringBuilder : NSObject <JInjectable>
@property (nonatomic, readonly, strong) NSMutableAttributedString* attributedString;
@end
