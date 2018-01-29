//
//  AWFCache.h
//  AerisCore
//
//  Created by Nicholas Shipes on 9/28/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AWFCache : NSObject

@property (readonly, copy) NSString *name;
@property (nonatomic) NSUInteger maxFilesize;
@property (readonly, nonatomic) NSUInteger currentFilesize;

- (instancetype)initWithName:(NSString *)name NS_DESIGNATED_INITIALIZER;

- (BOOL)objectExistsForKey:(NSString *)key;
- (id)objectForKey:(NSString *)key;
- (id)objectForKey:(NSString *)key withContent:(id (^)(void))content;
- (id)objectForKey:(NSString *)key expiresIn:(NSTimeInterval)expiresIn withContent:(id (^)(void))content;
- (id)objectForKey:(NSString *)key expires:(NSDate *)expires withContent:(id (^)(void))content;
- (id)objectInMemoryForKey:(NSString *)key;

- (void)setObject:(id)object forKey:(NSString *)key;
- (void)setObject:(id)object forKey:(NSString *)key expiresIn:(NSTimeInterval)expiresIn;
- (void)setObject:(id)object forKey:(NSString *)key expires:(NSDate *)expires;

- (void)removeObjectForKey:(NSString *)key;
- (void)removeAllObjects;
- (void)removeExpiredObjects;
- (void)trimFileSize;

@end


@protocol AWFExpirable <NSObject>
@property (nonatomic) NSDate *expires;
@end


@interface AWFCachedContent : NSObject <AWFExpirable, NSCopying, NSCoding>

@property (nonatomic) NSDate *expires;
@property (nonatomic) id object;

+ (instancetype)cachedContentWithObject:(id)object expires:(NSDate *)expires;

@end
