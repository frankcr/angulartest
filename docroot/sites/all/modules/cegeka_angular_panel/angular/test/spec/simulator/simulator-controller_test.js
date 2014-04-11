'use strict';

describe('Controller: SimulatorCtrl', function () {

    // load the controller's module
    beforeEach(module('angularPublicApp'));

    var simulatorCtrl,
        scope;

    // Initialize the controller and a mock scope
    beforeEach(inject(function ($controller, $rootScope) {
        scope = $rootScope.$new();
        simulatorCtrl = $controller('SimulatorCtrl', {
            $scope: scope
        });
    }));

    it('should attach a list of projects to the scope', function () {
        expect(scope.projects.length).toBe(4);
    });

});
