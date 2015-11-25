Pod::Spec.new do |s|
  s.name         = 'AerisWeather'
  s.version      = '2.2.1'
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

  s.platform     = :ios, '7.0'
  s.requires_arc = true
  s.default_subspecs = 'Aeris'

  s.subspec 'Aeris' do |ss|
    ss.vendored_frameworks = 'AerisWeatherSDK/Aeris.framework'
    ss.resources = 'AerisWeatherSDK/Aeris.bundle'
    ss.framework = 'Foundation'
    ss.dependency 'AFNetworking', '~> 2.6'
  end

  s.subspec 'AerisUI' do |ss|
    ss.vendored_frameworks = 'AerisWeatherSDK/AerisUI.framework'
    ss.resources = 'AerisWeatherSDK/AerisUI.bundle'
    ss.framework = 'UIKit'
  end

  s.subspec 'AerisMap' do |ss|
    ss.vendored_frameworks = 'AerisWeatherSDK/AerisMap.framework'
    ss.framework = 'MapKit'
    ss.dependency 'AerisWeather/AerisUI'
  end

  s.subspec 'AerisMapboxMap' do |ss|
    ss.vendored_frameworks = 'AerisWeatherSDK/AerisMapboxMap.framework'
    ss.dependency 'MBXMapKit'
    ss.dependency 'AerisWeather/AerisUI'
    ss.dependency 'AerisWeather/AerisMap'
  end

  s.subspec 'AerisGoogleMap' do |ss|
    ss.vendored_frameworks = 'AerisWeatherSDK/AerisGoogleMap.framework'
    ss.dependency 'GoogleMaps'
    ss.dependency 'AerisWeather/AerisUI'
    ss.dependency 'AerisWeather/AerisMap'
  end

end
