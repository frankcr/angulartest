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

        var getBaseUrl = function() {
            if (typeof Drupal !== 'undefined') {
                return Drupal.settings.cegeka_angular_panel.baseUrl;
            }
            return '';
        }

        $routeProvider
            .when('/simulator', {
                templateUrl: getBaseUrl() + 'views/simulator/simulator.html',
                controller: 'SimulatorCtrl'
            })
            .when('/creditrequest', {
                templateUrl: getBaseUrl() + 'views/creditrequest/creditrequest.html',
                controller: 'CreditRequestCtrl'
            })
            .otherwise({
                redirectTo: '/simulator'
            });
    });
