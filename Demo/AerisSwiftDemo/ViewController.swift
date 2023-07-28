//
//  ViewController.swift
//  AerisSwiftDemo
//
//  Created by Nicholas Shipes on 2/2/17.
//  Copyright © 2017 HAMweather, LLC. All rights reserved.
//

import UIKit

class MenuItem: NSObject {
	var title: String
	var controller: UIViewController
	
	init(title: String, controller: UIViewController) {
		self.title = title
		self.controller = controller
	}
}

class MenuCategory: NSObject {
	var title: String
	var items: [MenuItem]?
	
	init(title: String, items: [MenuItem]) {
		self.title = title
		self.items = items
	}
}

class ViewController: UIViewController {
	var tableView: UITableView!
	let controllerCache = NSCache<NSString, UIViewController>()
	var categories: [MenuCategory]!
	
	var endpoint: AWFWeatherEndpoint?

	override func viewDidLoad() {
		super.viewDidLoad()
		
		let locationItems = [MenuItem(title: "Location Search", controller: LocationSearchViewController())]
		
		let generalItems = [MenuItem(title: "Detailed Weather", controller: DetailedWeatherViewController())]
		
		categories = [MenuCategory(title: "Locations", items: locationItems),
					  MenuCategory(title: "General Weather", items: generalItems)]
		
//		NSArray *locationItems = @[@{ @"title": NSLocalizedString(@"Location Search", nil), @"class": [LocationSearchViewController class] }];
//
//		NSArray *generalItems, *graphItems;
//		if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
//			generalItems = @[@{ @"title": NSLocalizedString(@"Recent Observations", nil), @"class": [RecentObservationsViewController class] },
//			@{ @"title": NSLocalizedString(@"Nearby Observations", nil), @"class": [NearbyObservationsViewController class] },
//			@{ @"title": NSLocalizedString(@"Daily Summaries", nil), @"class": [DailySummariesViewController class] },
//			@{ @"title": NSLocalizedString(@"Weekend Forecast", nil), @"class": [WeekendWeatherViewController class] },
//			@{ @"title": NSLocalizedString(@"Sun & Moon", nil), @"class": [SunMoonViewController class] },
//			@{ @"title": NSLocalizedString(@"Moon Phases", nil), @"class": [MoonPhasesViewController class] },
//			@{ @"title": NSLocalizedString(@"Climate Normals", nil), @"class": [NormalsViewController class] },
//			@{ @"title": NSLocalizedString(@"Today's Tides", nil), @"class": [TidesViewController class] },
//			@{ @"title": NSLocalizedString(@"Indices", nil), @"class": [IndicesViewController class] },
//			@{ @"title": NSLocalizedString(@"Drought Monitor", nil), @"class": [DroughtMonitorViewController class] }
//			];
//
//			graphItems = @[@{ @"title": NSLocalizedString(@"Forecast (Line)", nil), @"class": [LineGraphsViewController_iPad class] },
//			@{ @"title": NSLocalizedString(@"Forecast (Bar)", nil), @"class": [BarGraphsViewController_iPad class] },
//			@{ @"title": NSLocalizedString(@"Forecast Models (Line)", nil), @"class": [ModelGraphsViewController_iPad class] }];
//		}
//		else {
//			generalItems = @[@{ @"title": NSLocalizedString(@"Detailed Weather", nil), @"class": [DetailedWeatherViewController class] },
//			@{ @"title": NSLocalizedString(@"Extended Forecast", nil), @"class": [ForecastViewController class] },
//			@{ @"title": NSLocalizedString(@"Recent Observations", nil), @"class": [RecentObservationsViewController class] },
//			@{ @"title": NSLocalizedString(@"Nearby Observations", nil), @"class": [NearbyObservationsViewController class] },
//			@{ @"title": NSLocalizedString(@"Weekend Forecast", nil), @"class": [WeekendWeatherViewController class] },
//			@{ @"title": NSLocalizedString(@"Daily Summaries", nil), @"class": [DailySummariesViewController class] },
//			@{ @"title": NSLocalizedString(@"Sun & Moon", nil), @"class": [SunMoonViewController class] },
//			@{ @"title": NSLocalizedString(@"Moon Phases", nil), @"class": [MoonPhasesViewController class] },
//			@{ @"title": NSLocalizedString(@"Climate Normals", nil), @"class": [NormalsViewController class] },
//			@{ @"title": NSLocalizedString(@"Today's Tides", nil), @"class": [TidesViewController class] },
//			@{ @"title": NSLocalizedString(@"Indices", nil), @"class": [IndicesViewController class] },
//			@{ @"title": NSLocalizedString(@"Drought Monitor", nil), @"class": [DroughtMonitorViewController class] }
//			];
//
//			graphItems = @[@{ @"title": NSLocalizedString(@"Forecast (Line)", nil), @"class": [ForecastLineGraphsViewController class] },
//			@{ @"title": NSLocalizedString(@"Forecast (Bar)", nil), @"class": [ForecastBarGraphsViewController class] },
//			@{ @"title": NSLocalizedString(@"Recent Obs (Line)", nil), @"class": [RecentObsGraphViewController class] },
//			@{ @"title": NSLocalizedString(@"Daily Summary (Bar)", nil), @"class": [DailySummaryGraphsViewController class] },
//			@{ @"title": NSLocalizedString(@"Forecast Models (Line)", nil), @"class": [ModelGraphsViewController class] }];
//		}
//
//		NSArray *severeItems = @[@{ @"title": NSLocalizedString(@"Active Advisories", nil), @"class": [AdvisoriesViewController class] },
//		@{ @"title": NSLocalizedString(@"Nearby Storm Cells", nil), @"class": [StormCellsViewController class] },
//		@{ @"title": NSLocalizedString(@"Nearby Storm Reports", nil), @"class": [StormReportsViewController class] },
//		@{ @"title": NSLocalizedString(@"Nearby Records", nil), @"class": [RecordsViewController class] },
//		@{ @"title": NSLocalizedString(@"Nearby Earthquakes", nil), @"class": [EarthquakesViewController class] },
//		@{ @"title": NSLocalizedString(@"Nearby Threats", nil), @"class": [ThreatsViewController class] },
//		@{ @"title": NSLocalizedString(@"Convective Outlook", nil), @"class": [ConvectiveOutlookViewController class] }
//		];
//
//		NSArray *imageItems = @[ //@{@"title": NSLocalizedString(@"Static Map Viewer", nil), @"class": [NSObject class]},
//		@{ @"title": NSLocalizedString(@"Apple Map", nil), @"class": [AppleMapViewController class] },
//		@{ @"title": NSLocalizedString(@"Google Map", nil), @"class": [GoogleMapViewController class] },
//		@{ @"title": NSLocalizedString(@"Mapbox Map", nil), @"class": [MapboxMapViewController class] }
//		];
//
//		self.categories = @[@{ @"title": NSLocalizedString(@"Locations", nil), @"items": locationItems },
//		@{ @"title": NSLocalizedString(@"General Weather", nil), @"items": generalItems },
//		@{ @"title": NSLocalizedString(@"Graphs", nil), @"items": graphItems },
//		@{ @"title": NSLocalizedString(@"Severe Weather", nil), @"items": severeItems },
//		@{ @"title": NSLocalizedString(@"Maps", nil), @"items": imageItems }
//		];
	}
	
	override func viewDidAppear(_ animated: Bool) {
		super.viewDidAppear(animated)
		
		tableView = UITableView()
		tableView.translatesAutoresizingMaskIntoConstraints = false
		tableView.dataSource = self
		tableView.delegate = self
		tableView.register(UITableViewCell.self, forCellReuseIdentifier: "MenuCell")
		view.addSubview(tableView)
		
		NSLayoutConstraint.activate([
			tableView.topAnchor.constraint(equalTo: view.topAnchor),
			tableView.leftAnchor.constraint(equalTo: view.leftAnchor),
			tableView.rightAnchor.constraint(equalTo: view.rightAnchor),
			tableView.bottomAnchor.constraint(equalTo: view.bottomAnchor)
		])
		
//		let place = AWFPlace(city: "seattle", state: "wa", country: "us")
//
//		endpoint = AWFObservations()
//		endpoint?.get(forPlace: place, options: nil) { (result) in
//			if let error = result?.error {
//				print(error)
//			} else if let results = result?.results {
//				print(results)
//			}
//		}
	}

	override func didReceiveMemoryWarning() {
		super.didReceiveMemoryWarning()
		// Dispose of any resources that can be recreated.
	}


}

extension ViewController: UITableViewDataSource {
	
	func numberOfSections(in tableView: UITableView) -> Int {
		return categories?.count ?? 0
	}
	
	func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
		return categories?[section].items?.count ?? 0
	}
	
	func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
		let cell = tableView.dequeueReusableCell(withIdentifier: "MenuCell", for: indexPath)
		
		if let category = categories?[indexPath.section], let item = category.items?[indexPath.row] {
			cell.textLabel?.text = item.title
		}
		
		return cell
	}
}

extension ViewController: UITableViewDelegate {
	
	func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
		if let category = categories?[indexPath.section], let item = category.items?[indexPath.row] {
			item.controller.title = item.title
			navigationController?.pushViewController(item.controller, animated: true)
		}
	}
}

