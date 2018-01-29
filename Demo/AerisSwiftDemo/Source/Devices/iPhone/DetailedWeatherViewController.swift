//
//  DetailedWeatherViewController.swift
//  AerisSwiftDemo
//
//  Created by Nicholas Shipes on 12/29/17.
//  Copyright © 2017 AerisWeather. All rights reserved.
//

import UIKit

class DetailedWeatherViewController: UIViewController {
	var obsView: AWFObservationView!
	var advisoriesView: AWFObservationAdvisoriesView!
	var todayView: AWFForecastDetailView!
	var tonightView: AWFForecastDetailView!
	var hourlyCollectionView: UICollectionView!
	
	fileprivate var hourlyPeriods: [AWFForecastPeriod]?
	
	override func viewDidLoad() {
		super.viewDidLoad()
		
		view.backgroundColor = AWFCascadingStyle().viewControllerBackgroundColor
		
		obsView = AWFObservationView()
		obsView.translatesAutoresizingMaskIntoConstraints = false
		view.addSubview(obsView)
		
		advisoriesView = AWFObservationAdvisoriesView()
		advisoriesView.translatesAutoresizingMaskIntoConstraints = false
		advisoriesView.alpha = 0
		view.addSubview(advisoriesView)
		
		let obsKeyline = UIView()
		obsKeyline.translatesAutoresizingMaskIntoConstraints = false
		obsKeyline.backgroundColor = UIColor(white: 0.8, alpha: 1.0)
		view.addSubview(obsKeyline)
		
		todayView = AWFForecastDetailView()
		todayView.translatesAutoresizingMaskIntoConstraints = false
		view.addSubview(todayView)
		
		tonightView = AWFForecastDetailView()
		tonightView.translatesAutoresizingMaskIntoConstraints = false
		view.addSubview(tonightView)
		
		let forecastKeyline = UIView()
		forecastKeyline.translatesAutoresizingMaskIntoConstraints = false
		forecastKeyline.backgroundColor = UIColor(white: 0.8, alpha: 1.0)
		view.addSubview(forecastKeyline)
		
		let hourlyCollectionViewLayout = UICollectionViewFlowLayout()
		hourlyCollectionViewLayout.scrollDirection = .horizontal
		hourlyCollectionViewLayout.minimumInteritemSpacing = 0
		hourlyCollectionViewLayout.minimumLineSpacing = 0
		hourlyCollectionViewLayout.itemSize = CGSize(width: 80.0, height: 50.0)
		
		hourlyCollectionView = UICollectionView(frame: .zero, collectionViewLayout: hourlyCollectionViewLayout)
		hourlyCollectionView.translatesAutoresizingMaskIntoConstraints = false
		hourlyCollectionView.backgroundColor = AWFCascadingStyle().viewControllerBackgroundColor
		hourlyCollectionView.dataSource = self
		hourlyCollectionView.delegate = self
		hourlyCollectionView.register(AWFCollectionViewHourlyBasicCell.self, forCellWithReuseIdentifier: AWFCollectionViewHourlyBasicCell.defaultReuseIdentifier())
		view.addSubview(hourlyCollectionView)
		
		// layout
		NSLayoutConstraint.activate([
			obsView.topAnchor.constraint(equalTo: view.topAnchor),
			obsView.leftAnchor.constraint(equalTo: view.leftAnchor),
			obsView.rightAnchor.constraint(equalTo: view.rightAnchor),
			
			obsKeyline.topAnchor.constraint(equalTo: obsView.bottomAnchor),
			obsKeyline.leftAnchor.constraint(equalTo: view.leftAnchor),
			obsKeyline.rightAnchor.constraint(equalTo: view.rightAnchor),
			obsKeyline.heightAnchor.constraint(equalToConstant: 2.0),
			
			todayView.topAnchor.constraint(equalTo: obsKeyline.bottomAnchor),
			todayView.leftAnchor.constraint(equalTo: view.leftAnchor),
			todayView.rightAnchor.constraint(equalTo: view.centerXAnchor),
			
			tonightView.topAnchor.constraint(equalTo: todayView.topAnchor),
			tonightView.leftAnchor.constraint(equalTo: view.centerXAnchor),
			tonightView.rightAnchor.constraint(equalTo: view.rightAnchor),
			
			forecastKeyline.topAnchor.constraint(equalTo: todayView.bottomAnchor),
			forecastKeyline.leftAnchor.constraint(equalTo: view.leftAnchor),
			forecastKeyline.rightAnchor.constraint(equalTo: view.rightAnchor),
			forecastKeyline.heightAnchor.constraint(equalToConstant: 2.0),
			
			hourlyCollectionView.topAnchor.constraint(equalTo: forecastKeyline.bottomAnchor),
			hourlyCollectionView.leftAnchor.constraint(equalTo: view.leftAnchor),
			hourlyCollectionView.rightAnchor.constraint(equalTo: view.rightAnchor),
			hourlyCollectionView.bottomAnchor.constraint(equalTo: view.bottomAnchor)
		])
	}
	
	override func viewDidLayoutSubviews() {
		super.viewDidLayoutSubviews()
		
		let hourlyCollectionViewLayout = UICollectionViewFlowLayout()
		hourlyCollectionViewLayout.scrollDirection = .horizontal
		hourlyCollectionViewLayout.minimumInteritemSpacing = 0
		hourlyCollectionViewLayout.minimumLineSpacing = 0
		hourlyCollectionViewLayout.itemSize = CGSize(width: 80.0, height: view.frame.height - hourlyCollectionView.frame.minY)
		hourlyCollectionView.collectionViewLayout = hourlyCollectionViewLayout
	}
	
	override func viewWillAppear(_ animated: Bool) {
		super.viewWillAppear(animated)
		
		if let style = Preferences.sharedInstance().preferredStyle() {
			view.backgroundColor = style.viewControllerBackgroundColor
			hourlyCollectionView.backgroundColor = style.viewControllerBackgroundColor
			
			obsView.apply(style)
			todayView.apply(style)
			tonightView.apply(style)
			hourlyCollectionView.reloadData()
		}
	}
	
	override func viewDidAppear(_ animated: Bool) {
		super.viewDidAppear(animated)
		
		if let place = UserLocationsManager.shared().defaultLocation() {
			loadData(forPlace: place)
		}
	}
	
	private func loadData(forPlace place: AWFPlace) {
		obsView.locationTextLabel.text = place.formattedNameFull
		
		// load latest observation data for place
		AWFObservations.sharedService().get(forPlace: place, options: nil) { [weak self] (result) in
			guard let results = result?.results else { print("Observation data failed to load - \(String(describing: result?.error))"); return }
			
			if let obs = results.first as? AWFObservation {
				// determine winds string
				let windSpeed = obs.windSpeedMPH
				var windStr = "\(String(describing: obs.windDirection)) \(windSpeed) mph"
				if windSpeed == 0 {
					windStr = "Calm"
				}
				
				self?.obsView.tempTextLabel.text = "\(obs.tempF)deg"
				self?.obsView.weatherTextLabel.text = obs.weather
				self?.obsView.feelslikeTextLabel.text = "Feels Like: \(obs.feelslikeF)deg"
				self?.obsView.windsTextLabel.text = windStr
				self?.obsView.dewpointTextLabel.text = "\(obs.dewpointF)deg"
				self?.obsView.humidityTextLabel.text = "\(obs.humidity)%"
				self?.obsView.pressureTextLabel.text = "\(obs.pressureIN) in"
				
				if let wxicon = obs.icon {
					self?.obsView.iconImageView.image = UIImage(named: wxicon)
				} else {
					self?.obsView.iconImageView.image = nil
				}
			}
		}
		
		// load 24-hour forecast
		let forecastOptions = AWFWeatherRequestOptions()
		forecastOptions.limit = 2
		forecastOptions.filterString = "\(AWFForecastFilter.dayNight)"
		
		AWFForecasts.sharedService().get(forPlace: place, options: forecastOptions) { [weak self] (result) in
			guard let results = result?.results else { print("24-hour forecast data failed to load - \(String(describing: result?.error))"); return }
			
			if let forecast = results.first as? AWFForecast {
				forecast.periods?.enumerated().forEach({ (index, period) in
					// determine which view to set the data on
					let forecastView = index == 1 ? self?.tonightView : self?.todayView
					
					forecastView?.tempTextLabel.text = period.isDay ? "\(period.maxTempF)" : "\(period.minTempF)"
					forecastView?.weatherTextLabel.text = period.weather
					
					if let direction = period.windDirection, let speedRange = period.windSpeedRangeMPH {
						forecastView?.windsTextLabel.text = "\(direction) \(speedRange) mph"
					}
					
					if let wxicon = period.icon {
						forecastView?.iconImageView.image = UIImage(named: wxicon)
					}
					
					// need to set the proper default timezone to use when formatting this location's date/time/day
					if period.timestamp != nil {
//						forecastView?.periodTextLabel.text = timestamp.
						//[period.timestamp awf_dayNameRelativeToNow:YES timeZone:period.timeZone];
					}
					
					// show snow instead of precip if snow is forecast
					if let weather = period.weather {
						if weather.lowercased().contains("snow") {
							forecastView?.precipTextLabel.text = "Snow"
							forecastView?.precipTextLabel.text = "\(period.snowIN) in"
						} else {
							forecastView?.precipTextLabel.text = "Precip"
							forecastView?.precipTextLabel.text = "\(period.precipIN) in"
						}
					}
				})
			}
		}
		
		// load hourly forecast
		let hourlyOptions = AWFWeatherRequestOptions()
		hourlyOptions.limit = 9
		hourlyOptions.filterString = "\(AWFForecastFilter.filter3Hour)"
		
		AWFForecasts.sharedService().get(forPlace: place, options: hourlyOptions) { [weak self] (result) in
			guard let results = result?.results else { print("Hourly forecast data failed to load - \(String(describing: result?.error))"); return }
			
			if let forecast = results.first as? AWFForecast {
				self?.hourlyPeriods = forecast.periods
			} else {
				self?.hourlyPeriods = nil
			}
			
			self?.hourlyCollectionView.reloadData()
		}
		
		// load advisories
		AWFAdvisories.sharedService().get(forPlace: place, options: nil) { [weak self] (result) in
			guard let results = result?.results else { print("Advisory data failed to load - \(String(describing: result?.error))"); return }
			
			if let advisories = results as? [AWFAdvisory], results.count > 0 {
				self?.advisoriesView.advisories = advisories
				UIView.animate(withDuration: 0.2, animations: {
					self?.advisoriesView.alpha = 1.0
				})
			} else {
				UIView.animate(withDuration: 0.2, animations: {
					self?.advisoriesView.alpha = 0
				})
			}
		}
	}
}

extension DetailedWeatherViewController: UICollectionViewDataSource {
	
	func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
		return hourlyPeriods?.count ?? 0
	}
	
	func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
		let cell = collectionView.dequeueReusableCell(withReuseIdentifier: AWFCollectionViewHourlyBasicCell.defaultReuseIdentifier(), for: indexPath)
		
		if let hourlyCell = cell as? AWFCollectionViewHourlyBasicCell, let period = hourlyPeriods?[indexPath.row] {
			hourlyCell.configure(with: period)
			if let style = obsView.style {
				hourlyCell.weatherView.apply(style)
			}
		}
		
		return cell
	}
}

extension DetailedWeatherViewController: UICollectionViewDelegate {
	
}
