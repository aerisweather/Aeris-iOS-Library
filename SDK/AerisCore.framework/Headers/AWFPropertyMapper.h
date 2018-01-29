//
//  AWFPropertyMapper.h
//  Aeris-API-Library
//
//  Created by Nicholas Shipes on 3/23/15.
//  Copyright (c) 2015 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AWFPropertyMapperExportOption) {
	AWFPropertyMapperExportOptionExcludeNullValue,
	AWFPropertyMapperExportOptionIncludeNullValue
};

typedef NS_ENUM(NSUInteger, AWFPropertyMapperFinalMappingDecoderOption) {
	AWFPropertyMapperFinalMappingDecoderOptionIncludeAllKeys,
	AWFPropertyMapperFinalMappingDecoderOptionExcludeAlreadyMappedKeys
};

typedef void (^AWFFinalMappingDecoderBlock)(NSDictionary *input, id object);
typedef void (^AWFFinalMappingEncoderBlock)(NSMutableDictionary *output, id object);

@protocol AWFPropertyMapperModelFactoryProtocol;

@interface AWFPropertyMapper : NSObject

- (instancetype)initWithModelFactory:(id<AWFPropertyMapperModelFactoryProtocol>)modelFactory;

- (BOOL)addMappings:(NSDictionary *)mappings forClass:(Class)klass;
- (BOOL)addMappings:(NSDictionary *)mappings forClass:(Class)klass error:(NSError *__autoreleasing*)error;
- (void)addMappingsFromPropertyMapper:(AWFPropertyMapper *)propertyMapper;

- (BOOL)setMappings:(NSDictionary *)mappings forClass:(Class)klass;
- (BOOL)setMappings:(NSDictionary *)mappings forClass:(Class)klass error:(NSError *__autoreleasing*)error;

- (void)setFinalMappingEncoder:(AWFFinalMappingEncoderBlock)encoder forClass:(Class)klass;
- (void)setFinalMappingDecoder:(AWFFinalMappingDecoderBlock)decoder forClass:(Class)klass withOption:(AWFPropertyMapperFinalMappingDecoderOption)option;

- (BOOL)removeMappingsForClass:(Class)klass;

- (id)createObjectWithClass:(Class)klass fromDictionary:(NSDictionary *)dictionary;
- (id)createObjectWithClass:(Class)klass fromDictionary:(NSDictionary *)dictionary errors:(NSArray *__autoreleasing*)errors;
- (void)updateObjectInstance:(id)instance usingDictionary:(NSDictionary *)dictionary;
- (void)updateObjectInstance:(id)instance usingDictionary:(NSDictionary *)dictionary mappingKey:(NSString *)mappingKey;

- (NSDictionary *)serializeObject:(id)object;
- (NSDictionary *)serializeObject:(id)object withOptions:(enum AWFPropertyMapperExportOption)options;

+ (NSDictionary *)generateMappingsFromClass:(Class)klass;
+ (NSDictionary *)generateMappingsWithKeys:(NSArray *)keys;

@end


@protocol AWFPropertyMapperModelFactoryProtocol <NSObject>

- (id)instanceForClass:(Class)klass withDictionary:(NSDictionary *)dictionary;

@end
