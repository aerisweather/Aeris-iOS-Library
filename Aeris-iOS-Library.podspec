Pod::Spec.new do |s|
  s.name         = 'Aeris-iOS-Library'
  s.version      = '2.2.0'
  s.summary      = 'Quickly integrate the Aeris Weather API data and map overlays into your iOS apps.'
  s.description  = <<-DESC
                      The Aeris iOS Weather Framework allows a developer to quickly and easily add weather content and functionality to their iOS applications quickly and easily without having to code anything themselves. It utilizes the Aeris API backend for data loading and is built on top of an object mapping system that efficiently loads requested weather content into third-party iOS applications, greatly reducing the amount of code and development needed on the developer end.
                    DESC

  s.homepage     = 'https://github.com/aerisweather/Aeris-iOS-Library'
  s.documentation_url = 'http://www.aerisweather.com/support/docs/toolkits/aeris-ios-sdk/'
  s.social_media_url = 'https://twitter.com/AerisDeveloper'
  s.license      = { :type => 'BSD', :file => 'LICENSE' }
  s.author       = { 'AerisWeather, LLC' => 'http://aerisweather.com' }
  s.source       = { :git => 'https://github.com/aerisweather/Aeris-iOS-Library.git', :tag => s.version.to_s }

  s.vendored_frameworks = 'AerisSDK/Aeris.framework'
  s.resources = 'AerisSDK/Aeris.bundle'
  s.framework = 'Foundation'
  s.dependency 'AFNetworking', '~> 2.6'

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.subspec 'AerisUI' do |ui|
    ui.vendored_frameworks = 'AerisSDK/AerisUI.framework'
    ui.resources = 'AerisSDK/AerisUI.bundle'
    ui.framework = 'UIKit'
  end

  s.subspec 'AerisMap' do |map|
    map.vendored_frameworks = 'AerisSDK/AerisMap.framework'
    map.framework = 'MapKit'
  end

  s.subspec 'AerisMapboxMap' do |mapbox|
    mapbox.vendored_frameworks = 'AerisSDK/AerisMapboxMap.framework'
    mapbox.dependency 'MBXMapKit'
  end

  s.subspec 'AerisGoogleMap' do |google|
    google.vendored_frameworks = 'AerisSDK/AerisGoogleMap.framework'
    google.dependency 'GoogleMaps'
  end

end
