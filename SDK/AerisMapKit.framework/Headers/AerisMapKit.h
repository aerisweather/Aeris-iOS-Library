//
//  AerisMap.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AerisWeatherKit.h>

#import <AerisMapKit/AWFMapGlobals.h>
#import <AerisMapKit/AWFMapCoordinateBounds.h>
#import <AerisMapKit/AWFOverlayMetadata.h>
#import <AerisMapKit/AWFWeatherMap.h>
#import <AerisMapKit/AWFWeatherMapConfig.h>
#import <AerisMapKit/AWFWeatherMapStyle.h>
#import <AerisMapKit/AWFWeatherMapDelegate.h>
#import <AerisMapKit/AWFWeatherMapDataSource.h>
#import <AerisMapKit/AWFWeatherMapContainerView.h>
#import <AerisMapKit/AWFMapStrategy.h>

#import <AerisMapKit/AWFMapLayer.h>
#import <AerisMapKit/AWFRasterLayer.h>
#import <AerisMapKit/AWFPointLayer.h>
#import <AerisMapKit/AWFShapeLayer.h>

#import <AerisMapKit/AWFMapContentSource.h>
#import <AerisMapKit/AWFRasterSource.h>
#import <AerisMapKit/AWFPointSource.h>
#import <AerisMapKit/AWFLabelSource.h>
#import <AerisMapKit/AWFShapeSource.h>
#import <AerisMapKit/AWFTileSource.h>
#import <AerisMapKit/AWFAmpTileSource.h>
#import <AerisMapKit/AWFAmpTileSourceProvider.h>
#import <AerisMapKit/AWFCombinedSource.h>
#import <AerisMapKit/AWFStyledMapItem.h>

#import <AerisMapKit/AWFWeatherLayer.h>
#import <AerisMapKit/AWFRasterMapLayer.h>
#import <AerisMapKit/AWFRasterMapLayerFilter.h>
#import <AerisMapKit/AWFBaseMapStyle.h>
#import <AerisMapKit/AWFRasterBlendMode.h>
#import <AerisMapKit/AWFRasterMask.h>
#import <AerisMapKit/AWFMapImageURL.h>
#import <AerisMapKit/AWFMapTileURL.h>

#import <AerisMapKit/AWFTileOverlayPath.h>
#import <AerisMapKit/AWFMultiShapeOverlay.h>
#import <AerisMapKit/AWFAnnotation.h>
#import <AerisMapKit/AWFAnnotationView.h>
#import <AerisMapKit/AWFPolygon.h>
#import <AerisMapKit/AWFPolyline.h>

#import <AerisMapKit/AWFMapItemStyle.h>
#import <AerisMapKit/AWFAnnotationStyle.h>
#import <AerisMapKit/AWFGroupedStyle.h>
#import <AerisMapKit/AWFTextLabelAnnotation.h>
#import <AerisMapKit/AWFTextAnnotationStyle.h>
#import <AerisMapKit/AWFEarthquakeAnnotationStyle.h>
#import <AerisMapKit/AWFFireAnnotationStyle.h>
#import <AerisMapKit/AWFLightningStrikeAnnotationStyle.h>
#import <AerisMapKit/AWFLongPressAnnotationStyle.h>
#import <AerisMapKit/AWFRecordAnnotationStyle.h>
#import <AerisMapKit/AWFRiverAnnotationStyle.h>
#import <AerisMapKit/AWFStormCellAnnotationStyle.h>
#import <AerisMapKit/AWFStormReportAnnotationStyle.h>

#import <AerisMapKit/AWFPolygonStyle.h>
#import <AerisMapKit/AWFConvectiveOutlookPolygonStyle.h>
#import <AerisMapKit/AWFDroughtIndexPolygonStyle.h>
#import <AerisMapKit/AWFFireOutlookPolygonStyle.h>
#import <AerisMapKit/AWFWarningPolygonStyle.h>

#import <AerisMapKit/AWFLegendConfig.h>
#import <AerisMapKit/AWFLegendMetadata.h>
#import <AerisMapKit/AWFBarLegend.h>
#import <AerisMapKit/AWFPointLegend.h>
#import <AerisMapKit/AWFLegendItemView.h>
#import <AerisMapKit/AWFLegendView.h>
#import <AerisMapKit/AWFGroupedLegendView.h>
#import <AerisMapKit/AWFLegendStyle.h>

#import <AerisMapKit/AWFAnimation.h>
#import <AerisMapKit/AWFAnimationTimeline.h>
#import <AerisMapKit/AWFImageAnimation.h>
#import <AerisMapKit/AWFImageAnimationLoader.h>
#import <AerisMapKit/AWFPointAnimation.h>
#import <AerisMapKit/AWFAnimatableOverlay.h>

#import <AerisMapKit/AWFMapControlStyle.h>
#import <AerisMapKit/AWFTimelineView.h>
#import <AerisMapKit/AWFBasicControlView.h>
#import <AerisMapKit/AWFObservationCalloutContentView.h>
#import <AerisMapKit/AWFDataLoading.h>

#import <AerisMapKit/AWFWeatherMapViewController.h>
#import <AerisMapKit/AWFMapOptionsViewController.h>
#import <AerisMapKit/AWFMapLayerOptionsViewController.h>

#import <AerisMapKit/AWFAppleMapStrategy.h>
#import <AerisMapKit/AWFMKRasterSource.h>
#import <AerisMapKit/AWFMKTileSource.h>
#import <AerisMapKit/AWFMKTileOverlay.h>
#import <AerisMapKit/AWFMKImageOverlay.h>
#import <AerisMapKit/AWFMKAnnotationView.h>
#import <AerisMapKit/AWFMKMultiShapeOverlay.h>
#import <AerisMapKit/AWFMKMultiShapeOverlayRenderer.h>
#import <AerisMapKit/AWFMKEarthquakeAnnotationView.h>
#import <AerisMapKit/AWFMKLightningStrikeAnnotationView.h>
#import <AerisMapKit/AWFMKStormCellAnnotationView.h>
#import <AerisMapKit/AWFMKTextLabelAnnotationView.h>
#import <AerisMapKit/AWFMKArrow.h>
#import <AerisMapKit/AWFMKPolygon.h>
#import <AerisMapKit/AWFMKPolyline.h>

#import <AerisMapKit/MKMapView+AerisMap.h>
