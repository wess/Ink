//
//  InkMarkdownAttributes.h
//  Ink
//
//  Created by Wess Cope on 5/6/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InkAttributes.h"

@interface InkMarkdownAttributes : NSObject
@property (strong, nonatomic) InkCodeAttributesBlock    blockcodeAttributes;
@property (strong, nonatomic) InkAttributesBlock        blockquoteAttributes;
@property (strong, nonatomic) InkAttributesBlock        blockhtmlAttributes;
@property (strong, nonatomic) InkHeaderAttributesBlock  headerAttributes;
@property (strong, nonatomic) InkAttributesBlock        hruleAttributes;
@property (strong, nonatomic) InkAttributesBlock        listAttributes;
@property (strong, nonatomic) InkAttributesBlock        listitemAttributes;
@property (strong, nonatomic) InkAttributesBlock        paragraphAttributes;
@property (strong, nonatomic) InkAttributesBlock        tableAttributes;
@property (strong, nonatomic) InkAttributesBlock        tableRowAttributes;
@property (strong, nonatomic) InkAttributesBlock        tableCellAttributes;
@property (strong, nonatomic) InkAttributesBlock        autolinkAttributes;
@property (strong, nonatomic) InkAttributesBlock        codespanAttributes;
@property (strong, nonatomic) InkAttributesBlock        doubleEmphasisAttributes;
@property (strong, nonatomic) InkAttributesBlock        emphasisAttributes;
@property (strong, nonatomic) InkAttributesBlock        imageAttributes;
@property (strong, nonatomic) InkAttributesBlock        linebreakAttributes;
@property (strong, nonatomic) InkLinkAttributesBlock    linkAttributes;
@property (strong, nonatomic) InkAttributesBlock        rawHtmlTagAttributes;
@property (strong, nonatomic) InkAttributesBlock        tripleEmphasisAttributes;
@property (strong, nonatomic) InkAttributesBlock        strikethroughAttributes;
@property (strong, nonatomic) InkAttributesBlock        superscriptAttributes;
@property (strong, nonatomic) InkAttributesBlock        entityAttributes;
@property (strong, nonatomic) InkAttributesBlock        normalTextAttributes;
@property (strong, nonatomic) InkAttributesBlock        docHeaderAttributes;
@property (strong, nonatomic) InkAttributesBlock        docFooterAttributes;
@end
