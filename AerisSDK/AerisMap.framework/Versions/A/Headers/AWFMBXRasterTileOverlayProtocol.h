//
//  AWFMBXRasterTileOverlayProtocol.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/18/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

@protocol MBXRasterTileOverlayDelegate;
@class MBXOfflineMapDatabase;

@protocol AWFMBXRasterTileOverlayProtocol <MKOverlay>

@property (weak, nonatomic) id<MBXRasterTileOverlayDelegate> delegate;

- (id)initWithMapID:(NSString *)mapID;
- (id)initWithMapID:(NSString *)mapID includeMetadata:(BOOL)includeMetadata includeMarkers:(BOOL)includeMarkers;
//- (id)initWithMapID:(NSString *)mapID includeMetadata:(BOOL)includeMetadata includeMarkers:(BOOL)includeMarkers imageQuality:(MBXRasterImageQuality)imageQuality;
- (id)initWithOfflineMapDatabase:(MBXOfflineMapDatabase *)offlineMapDatabase;

- (void)invalidateAndCancel;

@end