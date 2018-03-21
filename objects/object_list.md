List of standard LHADA objects
==============================

Generator level object (truth level)
------------------------------------

| Object type | Object id             | description                  |
|-------------|-----------------------|------------------------------|
| Particle    | Particle              | Truth level stable final state particle. |
| Jet         | JetAkXX-00    	      | Jet clustered from true visible particles with antikt-algorithm and distance parameter R=XX/10. XX=04,05,06, etc.|


Objects reconstructed in Run 2 ATLAS data
-----------------------------------------

| Object type | Object id             | description                  |
|-------------|-----------------------|------------------------------|
| Photon      | Photon-AtlasRun2-00   | Photon reconstructed with the ATLAS detectorin Run 2 conditions. Delphes datacard [delphes_card_ATLAS.tcl] ( https://github.com/delphes/delphes/blob/764f536462b646fdd0f033cc71c2b1539df6296a/cards/delphes_card_ATLAS.tcl)|								   
| Electron    | Electron-AtlasRun2-00 | Electron reconstructed with the ATLAS detectorin Run 2 conditions. Delphes datacard [delphes_card_ATLAS.tcl] ( https://github.com/delphes/delphes/blob/764f536462b646fdd0f033cc71c2b1539df6296a/cards/delphes_card_ATLAS.tcl)|								   
| Muon        | Muon-AtlasRun2-00     | Muon reconstructed with the ATLAS detectorin Run 2 conditions. Delphes datacard [delphes_card_ATLAS.tcl] ( https://github.com/delphes/delphes/blob/764f536462b646fdd0f033cc71c2b1539df6296a/cards/delphes_card_ATLAS.tcl)|								   
| MET         | Met-AtlasRun2-00      | Missing energy reconstructed with the ATLAS detectorin Run 2 conditions. Delphes datacard [delphes_card_ATLAS.tcl] ( https://github.com/delphes/delphes/blob/764f536462b646fdd0f033cc71c2b1539df6296a/cards/delphes_card_ATLAS.tcl)|							   
| Jet         | Jet-AtlasRun2Ak04-00  | Jet reconstructed with the ATLAS detector and clustered with anti-kt algorithm with distance parameter R=0.4 | 
| ST          | ST-AtlasRun2-00       | Transverse momentum scalar sum over all objects used in the reconstruction of ATLAS missing ET  |  

Objects reconstructed in Run 2 CMS data
-----------------------------------------

| Object type | Object id             | description                  |
|-------------|-----------------------|------------------------------|
| Photon      | Photon-CmsRun2-00     | Photon reconstructed with the CMS detector in Run2 conditions. Delphes datacard: [delphes_card_CMS.tcl] ( https://github.com/delphes/delphes/blob/764f536462b646fdd0f033cc71c2b1539df6296a/cards/delphes_card_CMS.tcl)|
| Electron    | Electron-CmsRun2-00   | Electron reconstructed with the CMS detectorin Run 2 conditions. Delphes datacard [delphes_card_CMS.tcl] ( https://github.com/delphes/delphes/blob/764f536462b646fdd0f033cc71c2b1539df6296a/cards/delphes_card_CMS.tcl)|
| Muon        | Muon-CmsRun2-00       | Muon reconstructed with the CMS detectorin Run 2 conditions. Delphes datacard [delphes_card_CMS.tcl] ( https://github.com/delphes/delphes/blob/764f536462b646fdd0f033cc71c2b1539df6296a/cards/delphes_card_CMS.tcl)|
| MET         | Met-CmsRun2-00        | Missing energy reconstructed with the CMS detectorin Run 2 conditions. Delphes datacard [delphes_card_CMS.tcl] ( https://github.com/delphes/delphes/blob/764f536462b646fdd0f033cc71c2b1539df6296a/cards/delphes_card_CMS.tcl)|
| Jet         | Jet-CmsRun2Ak04-00    | Jet reconstructed with the CMS detector and clustered with anti-kt algorithm with distance parameter R=0.4 in Run 2 conditions. Delphes datacard [delphes_card_CMS.tcl] ( https://github.com/delphes/delphes/blob/764f536462b646fdd0f033cc71c2b1539df6296a/cards/delphes_card_CMS.tcl)|
| ST          | ST-AtlasRun2-00       | Transverse momentum scalar sum over all objects used in the reconstruction of ATLAS missing ET  |

All collections listed in this page are ordered by decreasing pt