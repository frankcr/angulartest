'use strict';

angular.module('angularPublicApp')
    .controller('SimulatorCtrl', function ($scope) {
        $scope.selectedProjectType = 'car';

        $scope.projects = [
            {type: 'car'},
            {type: 'motor'},
            {type: 'construction'},
            {type: 'other'}
        ];
    });
