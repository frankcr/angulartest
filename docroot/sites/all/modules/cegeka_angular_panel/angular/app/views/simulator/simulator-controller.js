'use strict';

angular.module('angularPublicApp')
    .controller('SimulatorCtrl', function ($scope) {
		//TODO get default type from a drupal setting
        $scope.selectedProjectType = 'car';

        $scope.projects = [
            {type: 'car'},
            {type: 'motor'},
            {type: 'construction'},
            {type: 'other'}
        ];
    });
