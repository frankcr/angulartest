'use strict';
var applications = [
    {"lastModified":"2014-01-29T17:08:00.000",
        "maintenanceConfigCount":2,
        "name":"telegate"},
    {"lastModified":"2014-02-10T13:47:36.000",
        "maintenanceConfigCount":25,
        "name":"mijntelenet"}
];

angular.module('cetelemPublicApp_test', ['cetelemPublicApp', 'ngMockE2E'])
    .run(function ($httpBackend) {
        $httpBackend.whenGET('indexMocks.html').passThrough();
        $httpBackend.whenGET('views/creditrequest/creditrequest.html').passThrough();
        $httpBackend.whenGET('views/simulator/simulator.html').passThrough();

        $httpBackend.whenGET('/backend/rest/private/applications').respond(applications);
        $httpBackend.whenPOST('/backend/rest/private/v1/app/telegate/configs').respond(200);
    });
