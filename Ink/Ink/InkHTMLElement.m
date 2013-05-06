//
//  InkHTMLElement.m
//  Ink
//
//  Created by Wess Cope on 5/6/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import "InkHTMLElement.h"
#import <libxml/HTMLtree.h>

@interface InkHTMLElement()
@property (strong, nonatomic) NSDictionary *attributes;
@property (nonatomic) xmlNode *node;
@end

@implementation InkHTMLElement
@synthesize children    = _children;
@synthesize attributes  = _attributes;

+ (instancetype)inkHTMLElementWithNode:(xmlNode *)node;
{
    return [[[self class] alloc] initWithNode:node];
}

- (id)initWithNode:(xmlNode *)node
{
    self = [super init];
    if (self)
    {
        self.node = node;
    }
    return self;
}

#pragma mark - Properties -
- (InkHTMLElement *)parent
{
    return [InkHTMLElement inkHTMLElementWithNode:self.node->parent];
}

- (InkHTMLElement *)nextElement
{
    return [InkHTMLElement inkHTMLElementWithNode:self.node->next];
}

- (InkHTMLElement *)previousElement
{
    return [InkHTMLElement inkHTMLElementWithNode:self.node->prev];
}

- (NSArray  *)children
{
    if(_children)
        return _children;
    
    xmlNode *currentNode = NULL;
    NSMutableArray *kids = [[NSMutableArray alloc] init];
    
    for(currentNode = self.node->children; currentNode; currentNode = currentNode->next)
        [kids addObject:[InkHTMLElement inkHTMLElementWithNode:currentNode]];
    
    _children = kids;
    
    return _children;
}

- (NSDictionary *)attributes
{
    if(_attributes)
        return _attributes;
    
    xmlAttr *attribute                   = self.node->properties;
    NSMutableDictionary  *attributesDict = [[NSMutableDictionary alloc] init];
    
    while(attribute && attribute->name && attribute->children)
    {
        xmlChar *value                  = xmlNodeListGetString(self.node->doc, attribute->children, 1);
        NSString *attributeName         = [NSString stringWithCString:(const char *)attribute->name encoding:NSUTF8StringEncoding];
        attributesDict[attributeName]   = [NSString stringWithCString:(const char *)value encoding:NSUTF8StringEncoding];
    }
    
    _attributes = attributesDict;
    
    return _attributes;
}

- (NSString *)raw
{
    xmlBufferPtr buffer         = xmlBufferCreate();
    xmlOutputBufferPtr output   = xmlOutputBufferCreateBuffer(buffer, NULL);
    NSString *string            = nil;
    
    htmlNodeDumpOutput(output, self.node->doc, self.node, (const char *)self.node->doc->encoding);
    
    if(buffer->content)
        string = [[NSString alloc] initWithBytes:(const void *)xmlBufferContent(buffer) length:xmlBufferLength(buffer) encoding:NSUTF8StringEncoding];
    
    xmlOutputBufferClose(output);
    xmlBufferFree(buffer);
    
    return string;
}

- (NSString *)text
{
    return (self.node->children && self.node->children->content)? [NSString stringWithCString:(const char *)self.node->children->content encoding:NSUTF8StringEncoding] : nil;
}



@end
