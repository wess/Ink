//
//  InkCallbacks.h
//  Ink
//
//  Created by Wess Cope on 5/2/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import "markdown.h"
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "InkStringBuilder.h"
#import "InkAttributes.h"

#ifndef Ink_InkCallbacks_h
#define Ink_InkCallbacks_h

#define INK_STRING_FROM_BUFFER(buf)             [[NSString alloc] initWithData:[NSData dataWithBytes:buf->data length:buf->size] encoding:NSUTF8StringEncoding]
#define INK_STRING_BUILDER                      ((__bridge InkStringBuilder *)opaque)

static void appendTextWithAttributes(const struct buf *text, NSDictionary *attributes, void *opaque)
{
    NSString *outputString                  = INK_STRING_FROM_BUFFER(text);
    NSMutableAttributedString *attrString   = [[NSMutableAttributedString alloc] initWithString:outputString];

    if(attributes)
        [attrString addAttributes:attributes range:NSMakeRange(0, outputString.length)];

    [INK_STRING_BUILDER.attributedString appendAttributedString:attrString];
}

static void renderBlockcode(struct buf *ob, const struct buf *text, const struct buf *lang, void *opaque)
{
    NSString *language          = lang && lang->size > 0? INK_STRING_FROM_BUFFER(lang) : @"";
    NSString *code              = INK_STRING_FROM_BUFFER(text);
    NSDictionary *attributes    = INK_STRING_BUILDER.attributes.blockcodeAttributes(language, code);
    
    appendTextWithAttributes(text, attributes, opaque);
}

static void renderBlockquote(struct buf *ob, const struct buf *text, void *opaque)
{
    NSDictionary *attributes = INK_STRING_BUILDER.attributes.blockquoteAttributes(INK_STRING_FROM_BUFFER(text));
    appendTextWithAttributes(text, attributes, opaque);
}

static void renderBlockhtml(struct buf *ob,const  struct buf *text, void *opaque)
{
    NSDictionary *attributes = INK_STRING_BUILDER.attributes.blockquoteAttributes(INK_STRING_FROM_BUFFER(text));
    appendTextWithAttributes(text, attributes, opaque);
}

static void renderHeader(struct buf *ob, const struct buf *text, int level, void *opaque)
{
    struct buf *htext = (struct buf *)text;
    bufputc(htext, '\n');

    NSDictionary *attributes = INK_STRING_BUILDER.attributes.headerAttributes(INK_STRING_FROM_BUFFER(htext), level);
    appendTextWithAttributes(htext, attributes, opaque);

}

static void renderHrule(struct buf *ob, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderList(struct buf *ob, const struct buf *text, int flags, void *opaque)
{
    struct buf *ltext = (struct buf *)text;
    bufputc(ltext, '\n');
    
    NSDictionary *attributes = INK_STRING_BUILDER.attributes.blockquoteAttributes(INK_STRING_FROM_BUFFER(ltext));

    appendTextWithAttributes(ltext, attributes, opaque);
}

static void renderListitem(struct buf *ob, const struct buf *text, int flags, void *opaque)
{
    BOOL isOrderedList              = ((flags & MKD_LIST_ORDERED) != 0);
    InkStringBuilder *stringBuilder = (__bridge InkStringBuilder *)opaque;
    NSArray *bullets                = stringBuilder.listBulletCharacters;
    NSString *bullet;

    if(isOrderedList)
    {
        NSInteger index                 = stringBuilder.orderedListIndex + 1;
        stringBuilder.orderedListIndex  = index;
        bullet                          = [NSString stringWithFormat:@"%d.", index];
    }
    else if(bullets.count > stringBuilder.listDepth)
    {
        bullet = bullets[stringBuilder.listDepth];
    }

    bullet = [bullet stringByAppendingString:@" "];
    
    struct buf *litext = bufnew(256);
    bufputs(litext, [bullet UTF8String]);
    bufput(litext, text->data, text->size);

    NSDictionary *attributes = INK_STRING_BUILDER.attributes.listitemAttributes(INK_STRING_FROM_BUFFER(litext));
    appendTextWithAttributes(litext, attributes, opaque);
}

static void renderParagraph(struct buf *ob, const struct buf *text, void *opaque)
{
    struct buf *ptext = (struct buf *)text;
    bufputc(ptext, '\n');
    bufputc(ptext, '\n');

    NSDictionary *attributes = INK_STRING_BUILDER.attributes.paragraphAttributes(INK_STRING_FROM_BUFFER(ptext));
    appendTextWithAttributes(ptext, attributes, opaque);
}

static void renderTable(struct buf *ob, const struct buf *header, const struct buf *body, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderTableRow(struct buf *ob, const struct buf *text, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderTableCell(struct buf *ob, const struct buf *text, int flags, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}



/* span level callbacks - NULL or return 0 prints the span verbatim */
static int renderAutolink(struct buf *ob, const struct buf *link, enum mkd_autolink type, void *opaque)
{
    NSString *linkString = INK_STRING_FROM_BUFFER(link);
    if(linkString)
    {
        NSURL *linkUrl          = [NSURL URLWithString:linkString];
        
        NSDictionary *attributes = INK_STRING_BUILDER.attributes.linkAttributes(linkUrl, linkString, linkString);
        appendTextWithAttributes(link, attributes, opaque);
    }
    
    return 1;
}

static int renderCodespan(struct buf *ob, const struct buf *text, void *opaque)
{
    NSDictionary *attributes = INK_STRING_BUILDER.attributes.codespanAttributes(INK_STRING_FROM_BUFFER(text));
    appendTextWithAttributes(text, attributes, opaque);
    
    return 1;
}

static int renderDoubleEmphasis(struct buf *ob, const struct buf *text, void *opaque)
{
    NSDictionary *attributes = INK_STRING_BUILDER.attributes.doubleEmphasisAttributes(INK_STRING_FROM_BUFFER(text));
    appendTextWithAttributes(text, attributes, opaque);
    return 1;
}

static int renderEmphasis(struct buf *ob, const struct buf *text, void *opaque)
{
    NSDictionary *attributes = INK_STRING_BUILDER.attributes.emphasisAttributes(INK_STRING_FROM_BUFFER(text));
    appendTextWithAttributes(text, attributes, opaque);
    return 1;
}

static int renderImage(struct buf *ob, const struct buf *link, const struct buf *title, const struct buf *alt, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
    return 1;
}

static int renderLinebreak(struct buf *ob, void *opaque)
{
    NSDictionary *attributes = INK_STRING_BUILDER.attributes.linebreakAttributes(@"\n");
    NSAttributedString *lineBreak = [[NSAttributedString alloc] initWithString:@"\n" attributes:attributes];
    [INK_STRING_BUILDER.attributedString appendAttributedString:lineBreak];
    
    return 1;
}

static int renderLink(struct buf *ob, const struct buf *link, const struct buf *title, const struct buf *content, void *opaque)
{
    NSString *linkString = INK_STRING_FROM_BUFFER(link);
    if(linkString)
    {
        NSString *linkTitle     = title && title->size > 0? INK_STRING_FROM_BUFFER(link) : @"";
        NSString *linkContent   = INK_STRING_FROM_BUFFER(content);
        NSURL *linkUrl          = [NSURL URLWithString:linkString];
        
        NSDictionary *attributes = INK_STRING_BUILDER.attributes.linkAttributes(linkUrl, linkTitle, linkContent);
        appendTextWithAttributes(content, attributes, opaque);
    }
    
    return 1;
}

static int renderRawHtmlTag(struct buf *ob, const struct buf *tag, void *opaque)
{
    
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
    return 1;
}

static int renderTripleEmphasis(struct buf *ob, const struct buf *text, void *opaque)
{
    NSDictionary *attributes = INK_STRING_BUILDER.attributes.tripleEmphasisAttributes(INK_STRING_FROM_BUFFER(text));
    appendTextWithAttributes(text, attributes, opaque);

    return 1;
}

static int renderStrikethrough(struct buf *ob, const struct buf *text, void *opaque)
{
    NSDictionary *attributes = INK_STRING_BUILDER.attributes.strikethroughAttributes(INK_STRING_FROM_BUFFER(text));
    appendTextWithAttributes(text, attributes, opaque);

    return 1;
}

static int renderSuperscript(struct buf *ob, const struct buf *text, void *opaque)
{
    NSDictionary *attributes = INK_STRING_BUILDER.attributes.superscriptAttributes(INK_STRING_FROM_BUFFER(text));
    appendTextWithAttributes(text, attributes, opaque);
    return 1;
}


/* low level callbacks - NULL copies input directly into the output */
static void renderEntity(struct buf *ob, const struct buf *entity, void *opaque)
{
//    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderNormalText(struct buf *ob, const struct buf *text, void *opaque)
{
    bufput(ob, text->data, text->size);
}


/* header and footer */
static void renderDocHeader(struct buf *ob, void *opaque)
{
    //Not used, really, document start indication.
//    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderDocFooter(struct buf *ob, void *opaque)
{
    //Not used, really, document stop indication.
//    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

struct sd_callbacks inkCallbacks = {
    .blockcode          = renderBlockcode,
    .blockquote         = renderBlockquote,
    .blockhtml          = renderBlockhtml,
    .header             = renderHeader,
    .hrule              = renderHrule,
    .list               = renderList,
    .listitem           = renderListitem,
    .paragraph          = renderParagraph,
    .table              = renderTable,
    .table_row          = renderTableRow,
    .table_cell         = renderTableCell,
    .autolink           = renderAutolink,
    .codespan           = renderCodespan,
    .double_emphasis    = renderDoubleEmphasis,
    .emphasis           = renderEmphasis,
    .image              = renderImage,
    .linebreak          = renderLinebreak,
    .link               = renderLink,
    .raw_html_tag       = renderRawHtmlTag,
    .triple_emphasis    = renderTripleEmphasis,
    .strikethrough      = renderStrikethrough,
    .superscript        = renderSuperscript,
    .entity             = renderEntity,
    .normal_text        = renderNormalText,
    .doc_header         = renderDocHeader,
    .doc_footer         = renderDocFooter,
};

#endif
