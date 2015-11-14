//
//  AFFiresLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFFireFilterLarge;
extern NSString * const AWFFireFilterCritical;
extern NSString * const AWFFireFilterMODIS;

extern NSString * const AWFFireFieldId;
extern NSString * const AWFFireFieldDateTime;
extern NSString * const AWFFireFieldType;
extern NSString * const AWFFireFieldConfidence;
extern NSString * const AWFFireFieldArea;
extern NSString * const AWFFireFieldName;
extern NSString * const AWFFireFieldState;
extern NSString * const AWFFireFieldCountry;
extern NSString * const AWFFireFieldStationSource;
extern NSString * const AWFFireFieldSatelliteSource;

extern NSString * const AWFFireOutlookFilterFireWeather;
extern NSString * const AWFFireOutlookFilterDryLightning;
extern NSString * const AWFFireOutlookFilterAll;
extern NSString * const AWFFireOutlookFilterElevated;
extern NSString * const AWFFireOutlookFilterCritical;
extern NSString * const AWFFireOutlookFilterExtreme;
extern NSString * const AWFFireOutlookFilterIsolatedDryStorms;
extern NSString * const AWFFireOutlookFilterScatteredDryStorms;
extern NSString * const AWFFireOutlookFilterDay1;
extern NSString * const AWFFireOutlookFilterDay2;
extern NSString * const AWFFireOutlookFilterDay3;
extern NSString * const AWFFireOutlookFilterDay4;
extern NSString * const AWFFireOutlookFilterDay5;
extern NSString * const AWFFireOutlookFilterDay6;
extern NSString * const AWFFireOutlookFilterDay7;
extern NSString * const AWFFireOutlookFilterDay8;

extern NSString * const AWFFireOutlookFieldId;
extern NSString * const AWFFireOutlookFieldCategory;
extern NSString * const AWFFireOutlookFieldDay;
extern NSString * const AWFFireOutlookFieldRiskType;
extern NSString * const AWFFireOutlookFieldRiskName;
extern NSString * const AWFFireOutlookFieldRiskCode;
extern NSString * const AWFFireOutlookFieldRangeStart;
extern NSString * const AWFFireOutlookFieldRangeEnd;
extern NSString * const AWFFireOutlookFieldTimestamp;

/**
 *  `AWFFiresLoader` provides convenience methods for interacting with the
 *  [`fires` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/fires) of the Aeris API. All requests will
 *  return instances of `AWFFire` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFFiresLoader : AWFGeographicObjectLoader

//-----------------------------------------------------------------------------
// @name Requesting Data
//-----------------------------------------------------------------------------

/**
 *  Requests a fire based on its unique identifier.
 *
 *  @param fireId          The unique identifier of the fire to request data for.
 *  @param options         An `AWFRequestOptions` instance containing additional parameters to be used with the request (optional).
 *  @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 *		an array of associated `AWFObject` instances returned by the request and the error that occurred during the request, if any.
 */
- (void)getFireWithId:(NSString *)fireId
              options:(AWFRequestOptions *)options
           completion:(AWFObjectLoaderObjectCompletionBlock)completionBlock;

@end


/**
 *  `AWFFireOutlooksLoader` provides convenience methods for interacting with the
 *  [`fires/outlook` endpoint](http://www.hamweather.com/support/documentation/aeris/endpoints/fires/outlook) of the Aeris API. All requests will
 *  return instances of `AWFFireOutlook` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFFireOutlooksLoader : AWFGeographicObjectLoader

@end