'use strict';

angular
    .module('angularPublicApp', [
        'ngResource',
        'ngRoute',
        'ui.bootstrap'
    ])
    .config(function ($routeProvider, $locationProvider) {
        $locationProvider
            .html5Mode(false)
            .hashPrefix('!');

        var baseUrl = Drupal.settings.cegeka_angular_panel.baseUrl;
        $routeProvider
            .when('/simulator', {
                templateUrl: baseUrl + 'views/simulator/simulator.html',
                controller: 'SimulatorCtrl'
            })
            .when('/creditrequest', {
                templateUrl: baseUrl + 'views/creditrequest/creditrequest.html',
                controller: 'CreditRequestCtrl'
            })
            .otherwise({
                redirectTo: '/simulator'
            });
    });
