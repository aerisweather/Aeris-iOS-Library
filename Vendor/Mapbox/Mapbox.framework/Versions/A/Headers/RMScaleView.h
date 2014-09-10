//
//  RMScaleView.h
//  MapView
//
//  Created by Justin R. Miller on 7/26/13.
//
//

#import <UIKit/UIKit.h>

@class RMMapView;

@interface RMScaleView : UIView

- (id)initWithMapView:(RMMapView *)mapView;
- (void)updateScaleForZoom:(CGFloat)zoom;

@end
