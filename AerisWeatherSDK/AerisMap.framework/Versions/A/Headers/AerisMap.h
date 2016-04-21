//
//  AerisMap.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisUI/AerisUI.h>

#import <AerisMap/AWFMapGlobals.h>
#import <AerisMap/AWFCoordinateBounds.h>
#import <AerisMap/AWFOverlayMetadata.h>
#import <AerisMap/AWFLayerType.h>
#import <AerisMap/AWFWeatherMap.h>
#import <AerisMap/AWFWeatherMapConfig.h>
#import <AerisMap/AWFWeatherMapDelegate.h>
#import <AerisMap/AWFMapStrategy.h>

#import <AerisMap/AWFDataLayer.h>
#import <AerisMap/AWFImageDataLayer.h>
#import <AerisMap/AWFPointDataLayer.h>
#import <AerisMap/AWFTextPointDataLayer.h>
#import <AerisMap/AWFPolygonDataLayer.h>
#import <AerisMap/AWFTileDataLayer.h>
#import <AerisMap/AWFMultiDataLayer.h>
#import <AerisMap/AWFStyledMapItem.h>
#import <AerisMap/AWFStyledAnnotation.h>

#import <AerisMap/AWFMultiShapeOverlay.h>
#import <AerisMap/AWFAnnotation.h>
#import <AerisMap/AWFImageOverlay.h>
#import <AerisMap/AWFTileOverlayPath.h>
#import <AerisMap/AWFPolygon.h>
#import <AerisMap/AWFPolyline.h>
#import <AerisMap/AWFPolygonView.h>
#import <AerisMap/AWFMultiShapeOverlayView.h>
#import <AerisMap/AWFMultiShapeOverlayRenderer.h>

#import <AerisMap/AWFGroupIdentifier.h>
#import <AerisMap/AWFMapItemStyle.h>
#import <AerisMap/AWFAnnotationStyle.h>
#import <AerisMap/AWFTextLabelAnnotation.h>
#import <AerisMap/AWFTextAnnotationStyle.h>
#import <AerisMap/AWFEarthquakeAnnotationStyle.h>
#import <AerisMap/AWFFireAnnotationStyle.h>
#import <AerisMap/AWFLightningStrikeAnnotationStyle.h>
#import <AerisMap/AWFLongPressAnnotationStyle.h>
#import <AerisMap/AWFRecordAnnotationStyle.h>
#import <AerisMap/AWFStormCellAnnotationStyle.h>
#import <AerisMap/AWFStormReportAnnotationStyle.h>

#import <AerisMap/AWFPolygonStyle.h>
#import <AerisMap/AWFConvectiveOutlookPolygonStyle.h>
#import <AerisMap/AWFDroughtIndexPolygonStyle.h>
#import <AerisMap/AWFFireOutlookPolygonStyle.h>
#import <AerisMap/AWFWarningPolygonStyle.h>
#import <AerisMap/AWFStormCellConeOverlayStyle.h>

#import <AerisMap/AWFLegendStyle.h>
#import <AerisMap/AWFBarLegendStyle.h>
#import <AerisMap/AWFDataLegendStyle.h>
#import <AerisMap/AWFAccumulatedPrecipLegendStyle.h>
#import <AerisMap/AWFLightningStrikeLegendStyle.h>
#import <AerisMap/AWFRadarLegendStyle.h>
#import <AerisMap/AWFRecordLegendStyle.h>
#import <AerisMap/AWFTemperatureLegendStyle.h>
#import <AerisMap/AWFWindLegendStyle.h>
#import <AerisMap/AWFSnowDepthLegendStyle.h>
#import <AerisMap/AWFFutureSnowLegendStyle.h>

#import <AerisMap/AWFAnimation.h>
#import <AerisMap/AWFAnimationTimeline.h>
#import <AerisMap/AWFImageAnimation.h>
#import <AerisMap/AWFPointDataAnimation.h>
#import <AerisMap/AWFAnimatableOverlay.h>

#import <AerisMap/AWFMapControlStyle.h>
#import <AerisMap/AWFTimelineView.h>
#import <AerisMap/AWFBasicControlView.h>
#import <AerisMap/AWFLegendView.h>
#import <AerisMap/AWFWeatherMapLegendView.h>
#import <AerisMap/AWFObservationCalloutContentView.h>

#import <AerisMap/AWFWeatherMapViewController.h>
#import <AerisMap/AWFMapOptionsViewController.h>
#import <AerisMap/AWFTableSection.h>
#import <AerisMap/AWFTableSectionRow.h>

#import <AerisMap/AWFAppleMapStrategy.h>
#import <AerisMap/AWFMKImageDataLayer.h>
#import <AerisMap/AWFMKTileDataLayer.h>
#import <AerisMap/AWFMKAnnotationView.h>
#import <AerisMap/AWFEarthquakeAnnotationView.h>
#import <AerisMap/AWFLightningStrikeAnnotationView.h>
#import <AerisMap/AWFStormCellAnnotationView.h>
#import <AerisMap/AWFTextLabelAnnotationView.h>

#import <AerisMap/MKMapView+AerisMap.h>