//
//  Aeris.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AerisEngine.h>
#import <Aeris/AerisAPIClient.h>

#import <Aeris/AWFAccessPermissions.h>
#import <Aeris/AWFGlobals.h>
#import <Aeris/AWFLog.h>
#import <Aeris/AWFNetworkActivityIndicatorManager.h>
#import <Aeris/AWFObjectLoader.h>
#import <Aeris/AWFObject.h>
#import <Aeris/AWFGeographicObject.h>
#import <Aeris/AWFRequestOptions.h>
#import <Aeris/AWFRequestFilter.h>
#import <Aeris/AWFRequestQuery.h>
#import <Aeris/AWFGeoPolygon.h>
#import <Aeris/AWFRangeSummary.h>
#import <Aeris/AWFLocationManager.h>
#import <Aeris/AWFWeatherDataType.h>
#import <Aeris/AWFMeasurement.h>
#import <Aeris/AWFForecastModel.h>

#import <Aeris/AWFPlacesLoader.h>
#import <Aeris/AWFVenuesLoader.h>
#import <Aeris/AWFObservationsLoader.h>
#import <Aeris/AWFForecastsLoader.h>
#import <Aeris/AWFAdvisoriesLoader.h>
#import <Aeris/AWFSunMoonLoader.h>
#import <Aeris/AWFMoonPhasesLoader.h>
#import <Aeris/AWFNormalsLoader.h>
#import <Aeris/AWFRecordsLoader.h>
#import <Aeris/AWFEarthquakesLoader.h>
#import <Aeris/AWFStormReportsLoader.h>
#import <Aeris/AWFLightningStrikesLoader.h>
#import <Aeris/AWFStormCellsLoader.h>
#import <Aeris/AWFFiresLoader.h>
#import <Aeris/AWFTidesLoader.h>
#import <Aeris/AWFActivitiesLoader.h>
#import <Aeris/AWFIndicesLoader.h>
#import <Aeris/AWFThreatsLoader.h>
#import <Aeris/AWFPhrasesLoader.h>
#import <Aeris/AWFConvectiveLoader.h>
#import <Aeris/AWFDroughtLoader.h>
#import <Aeris/AWFBatchLoader.h>

#import <Aeris/AWFPlace.h>
#import <Aeris/AWFRelativeTo.h>
#import <Aeris/AWFVenue.h>
#import <Aeris/AWFObservation.h>
#import <Aeris/AWFObservationSummary.h>
#import <Aeris/AWFForecast.h>
#import <Aeris/AWFAdvisory.h>
#import <Aeris/AWFSunMoon.h>
#import <Aeris/AWFMoonPhase.h>
#import <Aeris/AWFNormal.h>
#import <Aeris/AWFNormalStation.h>
#import <Aeris/AWFRecord.h>
#import <Aeris/AWFEarthquake.h>
#import <Aeris/AWFStormReport.h>
#import <Aeris/AWFStormReportSummary.h>
#import <Aeris/AWFLightningStrike.h>
#import <Aeris/AWFStormCell.h>
#import <Aeris/AWFStormCellSummary.h>
#import <Aeris/AWFFire.h>
#import <Aeris/AWFFireOutlook.h>
#import <Aeris/AWFTide.h>
#import <Aeris/AWFTideStation.h>
#import <Aeris/AWFActivity.h>
#import <Aeris/AWFIndexPeriod.h>
#import <Aeris/AWFIndex.h>
#import <Aeris/AWFThreat.h>
#import <Aeris/AWFPhrase.h>
#import <Aeris/AWFStormThreat.h>
#import <Aeris/AWFConvectiveOutlook.h>
#import <Aeris/AWFDroughtIndex.h>

#import <Aeris/NSBundle+Aeris.h>
#import <Aeris/AWFObject+AutoCoding.h>
#import <Aeris/CLLocation+Aeris.h>
#import <Aeris/NSDate+Aeris.h>
#import <Aeris/NSDictionary+Aeris.h>
#import <Aeris/NSString+Aeris.h>
#import <Aeris/NSNumber+Aeris.h>
#import <Aeris/NSObject+Aeris.h>
#import <Aeris/NSArray+Aeris.h>
#import <Aeris/UIDevice+Aeris.h>