Pod::Spec.new do |s|
  s.name         = 'AerisWeather'
  s.version      = '3.0.0-rc.1'
  s.summary      = 'Quickly integrate the Aeris Weather API data and map overlays into your iOS apps.'
  s.description  = <<-DESC
                      The Aeris iOS Weather Framework allows a developer to quickly and easily add weather content and functionality to their iOS applications quickly and easily without having to code anything themselves. It utilizes the Aeris API backend for data loading and is built on top of an object mapping system that efficiently loads requested weather content into third-party iOS applications, greatly reducing the amount of code and development needed on the developer end.
                    DESC

  s.homepage     = 'https://github.com/aerisweather/Aeris-iOS-Library'
  s.documentation_url = 'http://www.aerisweather.com/support/docs/toolkits/aeris-ios-sdk/'
  s.social_media_url = 'https://twitter.com/AerisDeveloper'
  s.license      = { :type => 'BSD', :file => 'LICENSE.md' }
  s.author       = { 'AerisWeather, LLC' => 'http://aerisweather.com' }
  s.source       = {
    :http => "https://cdn.aerisapi.com/sdk/ios/builds/aerisweather-ios-sdk-#{s.version.to_s}.zip",
    :flatten => true
  }
  s.preserve_paths = '**'

  s.platform     = :ios, '9.0'
  s.requires_arc = true
  s.default_subspecs = 'Data'


  s.subspec 'Core' do |ss|
    ss.header_dir = 'AerisCore'
    ss.vendored_frameworks = 'AerisCore.framework'
    ss.framework = 'Foundation'
  end

  s.subspec 'CoreUI' do |ss|
    ss.header_dir = 'AerisCoreUI'
    ss.vendored_frameworks = 'AerisCoreUI.framework'
    ss.framework = 'UIKit'
    ss.dependency 'AerisWeather/Core'
  end

  s.subspec 'Data' do |ss|
    ss.header_dir = 'AerisWeatherKit'
    ss.vendored_frameworks = 'AerisWeatherKit.framework'
    ss.dependency 'AerisWeather/CoreUI'
  end

  s.subspec 'Maps' do |ss|
    ss.header_dir = 'AerisMapKit'
    ss.vendored_frameworks = 'AerisMapKit.framework'
    ss.framework = 'MapKit'
    ss.dependency 'AerisWeather/Data'
  end

  s.subspec 'Mapbox' do |ss|
    ss.header_dir = 'AerisMapboxMapKit'
    ss.vendored_frameworks = 'AerisMapboxMapKit.framework'
    ss.dependency 'Mapbox-iOS-SDK'
    ss.dependency 'AerisWeather/Maps'
  end

  s.subspec 'Google' do |ss|
    ss.header_dir = 'AerisGoogleMapKit'
    ss.vendored_frameworks = 'AerisGoogleMapKit.framework'
    ss.dependency 'GoogleMaps'
    ss.dependency 'AerisWeather/Maps'
  end

end
