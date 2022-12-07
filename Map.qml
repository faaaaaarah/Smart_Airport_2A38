import QtQuick 2.0
import QtLocation 5.6


Rectangle {
    Plugin {
        id: myPlugin
        name: "osm" // "mapboxgl", "esri", ...
        //specify plugin parameters if necessary
        //PluginParameter {...}
        //PluginParameter {...}
        //...
    }
    property variant locationTunisie: QtPositioning.coordinate( 0,0)

    PlaceSearchModel {
        id: searchModel

        plugin: myPlugin

        searchTerm: "Tunis"
        searchArea: QtPositioning.circle(locationTunisie)

        Component.onCompleted: update()
    }
    Map {
        id: map
        anchors.fill: parent
        plugin: myPlugin;
        center {
            // The Qt Company in Oslo
            latitude: 36.80278
            longitude: 10.17972
        }
        zoomLevel: 13

        MapItemView {
            model: searchModel
            delegate: MapQuickItem {
                coordinate: place.location.coordinate

                anchorPoint.x: image.width/1000
                anchorPoint.y: image.height

                sourceItem: Column {
                    Image { id: image; source: "qrc:/marker.png" }
                    Text { text: title; font.bold: true }
                }
            }
        }
    }

}
