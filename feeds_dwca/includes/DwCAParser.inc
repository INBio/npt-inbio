<?php

/**
 * Parses a given file as a DwC-A file.
 */
class DwCAParser extends FeedsParser{

  /**
   * Overrides FeedsParser::getMappingSources()
   */
  public function getMappingSources() {

    $sources = parent::getMappingSources();

    $sources += array(
        'http://purl.org/dc/terms/type' => array (
            'name' => 'http://purl.org/dc/terms/type',
            'description' => 'The nature or genre of the resource. For Darwin Core, recommended best practice is to use the name of the class that defines the root of the record.',
            'optional_unique' => false),

        'http://purl.org/dc/terms/modified'  => array (
            'name' => 'http://purl.org/dc/terms/modified',
            'description' => 'The most recent date-time on which the resource was changed. For Darwin Core, recommended best practice is to use an encoding scheme, such as ISO 8601:2004(E)',
            'optional_unique' => false),

        'http://purl.org/dc/terms/language' => array (
            'name' => 'http://purl.org/dc/terms/language',
            'description' => 'A language of the resource. Recommended best practice is to use a controlled vocabulary such as RFC 4646 [RFC4646]',
            'optional_unique' => false),

        'http://purl.org/dc/terms/rights' => array (
            'name' => 'http://purl.org/dc/terms/rights',
            'description' => 'Information about rights held in and over the resource. Typically, rights information includes a statement about various property rights associated with the resource, including intellectual property rights',
            'optional_unique' => false),

        'http://purl.org/dc/terms/rightsHolder' => array (
            'name' => 'http://purl.org/dc/terms/rightsHolder',
            'description' => 'A person or organization owning or managing rights over the resource',
            'optional_unique' => false),

        'http://purl.org/dc/terms/accessRights' => array (
            'name' => 'http://purl.org/dc/terms/accessRights',
            'description' => 'Information about who can access the resource or an indication of its security status. Access Rights may include information regarding access or restrictions based on privacy, security, or other policies',
            'optional_unique' => false),

        'http://purl.org/dc/terms/bibliographicCitation' => array (
            'name' => 'http://purl.org/dc/terms/bibliographicCitation',
            'description' => 'A bibliographic reference for the resource as a statement indicating how this record should be cited (attributed) when used. Recommended practice is to include sufficient bibliographic detail to identify the resource as unambiguously as possible',
            'optional_unique' => false),

        'http://purl.org/dc/terms/references' => array (
            'name' => 'http://purl.org/dc/terms/references',
            'description' => 'A URL to a related resource that is referenced, cited, or otherwise pointed to by the described resource. Often another webpage showing the same, but richer resource',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/institutionID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/institutionID',
            'description' => 'An identifier for the institution having custody of the object(s) or information referred to in the record.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/collectionID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/collectionID',
            'description' => 'An identifier for the collection or dataset from which the record was derived. For physical specimens, the recommended best practice is to use the identifier in a collections registry such as the Biodiversity Collections Index (http://www.biodiversitycollectionsindex.org/).',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/datasetID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/datasetID',
            'description' => 'An identifier for the set of data. May be a global unique identifier or an identifier specific to a collection or institution.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/institutionCode' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/institutionCode',
            'description' => 'The name (or acronym) in use by the institution having custody of the object(s) or information referred to in the record.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/collectionCode' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/collectionCode',
            'description' => 'The name, acronym, coden, or initialism identifying the collection or data set from which the record was derived.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/datasetName' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/datasetName',
            'description' => 'The name identifying the data set from which the record was derived.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/ownerInstitutionCode' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/ownerInstitutionCode',
            'description' => 'The name (or acronym) in use by the institution having ownership of the object(s) or information referred to in the record.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/basisOfRecord' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/basisOfRecord',
            'description' => 'The specific nature of the data record - a subtype of the dcterms:type. Recommended best practice is to use a controlled vocabulary such as the Darwin Core Type Vocabulary (http://rs.tdwg.org/dwc/terms/type-vocabulary/index.htm).',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/informationWithheld' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/informationWithheld',
            'description' => 'Additional information that exists, but that has not been shared in the given record.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/dataGeneralizations' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/dataGeneralizations',
            'description' => 'Actions taken to make the shared data less specific or complete than in its original form. Suggests that alternative data of higher quality may be available on request.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/dynamicProperties' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/dynamicProperties',
            'description' => 'A list (concatenated and separated) of additional measurements, facts, characteristics, or assertions about the record. Meant to provide a mechanism for structured content such as key-value pairs.',
            'optional_unique' => false),

        'http://purl.org/dc/terms/source' => array (
            'name' => 'http://purl.org/dc/terms/source',
            'description' => 'Deprecated in favor over dcterm:references! A URI link to the source of this record. A link to a webpage or RESTful webservice is recommended.  URI is mandatory format.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/occurrenceID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/occurrenceID',
            'description' => 'An identifier for the Occurrence (as opposed to a particular digital record of the occurrence). In the absence of a persistent global unique identifier, construct one from a combination of identifiers in the record that will most closely make the occurrenceID globally unique.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/catalogNumber' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/catalogNumber',
            'description' => 'An identifier (preferably unique) for the record within the data set or collection.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/occurrenceRemarks' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/occurrenceRemarks',
            'description' => 'Comments or notes about the Occurrence.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/recordNumber' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/recordNumber',
            'description' => 'An identifier given to the Occurrence at the time it was recorded. Often serves as a link between field notes and an Occurrence record, such as a specimen collector&apos;s number.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/recordedBy' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/recordedBy',
            'description' => 'A list (concatenated and separated) of names of people, groups, or organizations responsible for recording the original Occurrence. The primary collector or observer, especially one who applies a personal identifier (recordNumber), should be listed first.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/individualID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/individualID',
            'description' => 'An identifier for an individual or named group of individual organisms represented in the Occurrence. Meant to accommodate resampling of the same individual or group for monitoring purposes. May be a global unique identifier or an identifier specific to a data set.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/individualCount' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/individualCount',
            'description' => 'The number of individuals represented present at the time of the Occurrence.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/sex' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/sex',
            'description' => 'The sex of the biological individual(s) represented in the Occurrence. Recommended best practice is to use a controlled vocabulary.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/lifeStage' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/lifeStage',
            'description' => 'The age class or life stage of the biological individual(s) at the time the Occurrence was recorded. Recommended best practice is to use a controlled vocabulary.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/reproductiveCondition' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/reproductiveCondition',
            'description' => 'The reproductive condition of the biological individual(s) represented in the Occurrence. Recommended best practice is to use a controlled vocabulary.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/behavior' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/behavior',
            'description' => 'A description of the behavior shown by the subject at the time the Occurrence was recorded.  Recommended best practice is to use a controlled vocabulary.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/establishmentMeans' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/establishmentMeans',
            'description' => 'The process by which the biological individual(s) represented in the Occurrence became established at the location. Recommended best practice is to use a controlled vocabulary.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/occurrenceStatus' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/occurrenceStatus',
            'description' => 'A statement about the presence or absence of a Taxon at a Location. Recommended best practice is to use a controlled vocabulary.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/preparations' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/preparations',
            'description' => 'A list (concatenated and separated) of preparations and preservation methods for a specimen.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/disposition' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/disposition',
            'description' => 'The current state of a specimen with respect to the collection identified in collectionCode or collectionID. Recommended best practice is to use a controlled vocabulary.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/otherCatalogNumbers' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/otherCatalogNumbers',
            'description' => 'A list (concatenated and separated) of previous or alternate fully qualified catalog numbers or other human-used identifiers for the same Occurrence, whether in the current or any other data set or collection.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/previousIdentifications' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/previousIdentifications',
            'description' => 'A list (concatenated and separated) of previous assignments of names to the Occurrence.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/associatedMedia' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/associatedMedia',
            'description' => 'A list (concatenated and separated) of identifiers (publication, global unique identifier, URI) of media associated with the Occurrence.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/associatedReferences' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/associatedReferences',
            'description' => 'A list (concatenated and separated) of identifiers (publication, bibliographic reference, global unique identifier, URI) of literature associated with the Occurrence.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/associatedOccurrences' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/associatedOccurrences',
            'description' => 'A list (concatenated and separated) of identifiers of other Occurrence records and their associations to this Occurrence.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/associatedSequences' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/associatedSequences',
            'description' => 'A list (concatenated and separated) of identifiers (publication, global unique identifier, URI) of genetic sequence information associated with the Occurrence.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/associatedTaxa' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/associatedTaxa',
            'description' => 'A list (concatenated and separated) of identifiers or names of taxa and their associations with the Occurrence.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/occurrenceDetails' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/occurrenceDetails',
            'description' => 'This term is deprecated in favor over the new dcterm:references. Previously this term was used as: A reference (publication, URI) to the most detailed information available about the Occurrence.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/eventID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/eventID',
            'description' => 'An identifier for the set of information associated with an Event (something that occurs at a place and time). May be a global unique identifier or an identifier specific to the data set.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/samplingProtocol' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/samplingProtocol',
            'description' => 'The name of, reference to, or description of the method or protocol used during an Event.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/samplingEffort' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/samplingEffort',
            'description' => 'The amount of effort expended during an Event.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/eventDate' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/eventDate',
            'description' => 'The date-time or interval during which an Event occurred. For occurrences, this is the date-time when the event was recorded. Not suitable for a time in a geological context. Recommended best practice is to use an encoding scheme, such as ISO 8601:2004(E).',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/eventTime' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/eventTime',
            'description' => 'The time or interval during which an Event occurred. Recommended best practice is to use an encoding scheme, such as ISO 8601:2004(E).',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/startDayOfYear' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/startDayOfYear',
            'description' => 'The earliest ordinal day of the year on which the Event occurred (1 for January 1, 365 for December 31, except in a leap year, in which case it is 366).',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/endDayOfYear' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/endDayOfYear',
            'description' => 'The latest ordinal day of the year on which the Event occurred (1 for January 1, 365 for December 31, except in a leap year, in which case it is 366).',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/year' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/year',
            'description' => 'The four-digit year in which the Event occurred, according to the Common Era Calendar.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/month' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/month',
            'description' => 'The ordinal month in which the Event occurred.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/day' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/day',
            'description' => 'The integer day of the month on which the Event occurred.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/verbatimEventDate' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/verbatimEventDate',
            'description' => 'The verbatim original representation of the date and time information for an Event.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/habitat' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/habitat',
            'description' => 'A category or description of the habitat in which the Event occurred.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/fieldNumber' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/fieldNumber',
            'description' => 'An identifier given to the event in the field. Often serves as a link between field notes and the Event.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/fieldNotes' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/fieldNotes',
            'description' => 'One of a) an indicator of the existence of, b) a reference to (publication, URI), or c) the text of notes taken in the field about the Event.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/eventRemarks' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/eventRemarks',
            'description' => 'Comments or notes about the Event.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/locationID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/locationID',
            'description' => 'An identifier for the set of location information (data associated with dcterms:Location). May be a global unique identifier or an identifier specific to the data set.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/higherGeographyID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/higherGeographyID',
            'description' => 'An identifier for the geographic region within which the Location occurred. Recommended best practice is to use an persistent identifier from a controlled vocabulary such as the Getty Thesaurus of Geographic Names.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/higherGeography' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/higherGeography',
            'description' => 'A list (concatenated and separated) of geographic names less specific than the information captured in the locality term.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/continent' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/continent',
            'description' => 'The name of the continent in which the Location occurs. Recommended best practice is to use a controlled vocabulary such as the Getty Thesaurus of Geographic Names or the ISO 3166 Continent code.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/waterBody' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/waterBody',
            'description' => 'The name of the water body in which the Location occurs. Recommended best practice is to use a controlled vocabulary such as the Getty Thesaurus of Geographic Names.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/islandGroup' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/islandGroup',
            'description' => 'The name of the island group in which the Location occurs. Recommended best practice is to use a controlled vocabulary such as the Getty Thesaurus of Geographic Names.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/island' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/island',
            'description' => 'The name of the island on or near which the Location occurs. Recommended best practice is to use a controlled vocabulary such as the Getty Thesaurus of Geographic Names.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/country' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/country',
            'description' => 'The name of the country or major administrative unit in which the Location occurs. Recommended best practice is to use a controlled vocabulary such as the Getty Thesaurus of Geographic Names.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/countryCode' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/countryCode',
            'description' => 'The standard code for the country in which the Location occurs. Recommended best practice is to use ISO 3166-1-alpha-2 country codes.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/stateProvince' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/stateProvince',
            'description' => 'The name of the next smaller administrative region than country (state, province, canton, department, region, etc.) in which the Location occurs.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/county' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/county',
            'description' => 'The full, unabbreviated name of the next smaller administrative region than stateProvince (county, shire, department, etc.) in which the Location occurs.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/municipality' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/municipality',
            'description' => 'The full, unabbreviated name of the next smaller administrative region than county (city, municipality, etc.) in which the Location occurs. Do not use this term for a nearby named place that does not contain the actual location.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/locality' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/locality',
            'description' => 'The specific description of the place. Less specific geographic information can be provided in other geographic terms (higherGeography, continent, country, stateProvince, county, municipality, waterBody, island, islandGroup). This term may contain information modified from the original to correct perceived errors or standardize the description.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/verbatimLocality' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/verbatimLocality',
            'description' => 'The original textual description of the place.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/verbatimElevation' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/verbatimElevation',
            'description' => 'The original description of the elevation (altitude, usually above sea level) of the Location.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/minimumElevationInMeters' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/minimumElevationInMeters',
            'description' => 'The lower limit of the range of elevation (altitude, usually above sea level), in meters.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/maximumElevationInMeters' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/maximumElevationInMeters',
            'description' => 'The upper limit of the range of elevation (altitude, usually above sea level), in meters.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/verbatimDepth' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/verbatimDepth',
            'description' => 'The original description of the depth below the local surface.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/minimumDepthInMeters' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/minimumDepthInMeters',
            'description' => 'The lesser depth of a range of depth below the local surface, in meters.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/maximumDepthInMeters' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/maximumDepthInMeters',
            'description' => 'The greater depth of a range of depth below the local surface, in meters.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/minimumDistanceAboveSurfaceInMeters' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/minimumDistanceAboveSurfaceInMeters',
            'description' => 'The lesser distance in a range of distance from a reference surface in the vertical direction, in meters. Use positive values for locations above the surface, negative values for locations below. If depth measures are given, the reference surface is the location given by the depth, otherwise the reference surface is the location given by the elevation.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/maximumDistanceAboveSurfaceInMeters' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/maximumDistanceAboveSurfaceInMeters',
            'description' => 'The greater distance in a range of distance from a reference surface in the vertical direction, in meters. Use positive values for locations above the surface, negative values for locations below. If depth measures are given, the reference surface is the location given by the depth, otherwise the reference surface is the location given by the elevation.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/locationAccordingTo' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/locationAccordingTo',
            'description' => 'Information about the source of this Location information. Could be a publication (gazetteer), institution, or team of individuals.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/locationRemarks' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/locationRemarks',
            'description' => 'Comments or notes about the Location.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/verbatimCoordinates' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/verbatimCoordinates',
            'description' => 'The verbatim original spatial coordinates of the Location. The coordinate ellipsoid, geodeticDatum, or full Spatial Reference System (SRS) for these coordinates should be stored in verbatimSRS and the coordinate system should be stored in verbatimCoordinateSystem.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/verbatimLatitude' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/verbatimLatitude',
            'description' => 'The verbatim original latitude of the Location. The coordinate ellipsoid, geodeticDatum, or full Spatial Reference System (SRS) for these coordinates should be stored in verbatimSRS and the coordinate system should be stored in verbatimCoordinateSystem.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/verbatimLongitude' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/verbatimLongitude',
            'description' => 'The verbatim original longitude of the Location. The coordinate ellipsoid, geodeticDatum, or full Spatial Reference System (SRS) for these coordinates should be stored in verbatimSRS and the coordinate system should be stored in verbatimCoordinateSystem.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/verbatimCoordinateSystem' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/verbatimCoordinateSystem',
            'description' => 'The spatial coordinate system for the verbatimLatitude and verbatimLongitude or the verbatimCoordinates of the Location. Recommended best practice is to use a controlled vocabulary.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/verbatimSRS' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/verbatimSRS',
            'description' => 'The ellipsoid, geodetic datum, or spatial reference system (SRS) upon which coordinates given in verbatimLatitude and verbatimLongitude, or verbatimCoordinates are based. Recommended best practice is use the EPSG code as a controlled vocabulary to provide an SRS, if known. Otherwise use a controlled vocabulary for the name or code of the geodetic datum, if known. Otherwise use a controlled vocabulary for the name or code of the ellipsoid, if known. If none of these is known, use the value "unknown".',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/decimalLatitude' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/decimalLatitude',
            'description' => 'The geographic latitude (in decimal degrees, using the spatial reference system given in geodeticDatum) of the geographic center of a Location. Positive values are north of the Equator, negative values are south of it. Legal values lie between -90 and 90, inclusive.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/decimalLongitude' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/decimalLongitude',
            'description' => 'The geographic longitude (in decimal degrees, using the spatial reference system given in geodeticDatum) of the geographic center of a Location. Positive values are east of the Greenwich Meridian, negative values are west of it. Legal values lie between -180 and 180, inclusive.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/geodeticDatum' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/geodeticDatum',
            'description' => 'The ellipsoid, geodetic datum, or spatial reference system (SRS) upon which the geographic coordinates given in decimalLatitude and decimalLongitude as based. Recommended best practice is use the EPSG code as a controlled vocabulary to provide an SRS, if known. Otherwise use a controlled vocabulary for the name or code of the geodetic datum, if known. Otherwise use a controlled vocabulary for the name or code of the ellipsoid, if known. If none of these is known, use the value "unknown".',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/coordinateUncertaintyInMeters' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/coordinateUncertaintyInMeters',
            'description' => 'The horizontal distance (in meters) from the given decimalLatitude and decimalLongitude describing the smallest circle containing the whole of the Location. Leave the value empty if the uncertainty is unknown, cannot be estimated, or is not applicable (because there are no coordinates). Zero is not a valid value for this term.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/coordinatePrecision' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/coordinatePrecision',
            'description' => 'A decimal representation of the precision of the coordinates given in the decimalLatitude and decimalLongitude.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/pointRadiusSpatialFit' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/pointRadiusSpatialFit',
            'description' => 'The ratio of the area of the point-radius (decimalLatitude, decimalLongitude, coordinateUncertaintyInMeters) to the area of the true (original, or most specific) spatial representation of the Location. Legal values are 0, greater than or equal to 1, or undefined. A value of 1 is an exact match or 100% overlap. A value of 0 should be used if the given point-radius does not completely contain the original representation. The pointRadiusSpatialFit is undefined (and should be left blank) if the original representation is a point without uncertainty and the given georeference is not that same point (without uncertainty). If both the original and the given georeference are the same point, the pointRadiusSpatialFit is 1.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/footprintWKT' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/footprintWKT',
            'description' => 'A Well-Known Text (WKT) representation of the shape (footprint, geometry) that defines the Location. A Location may have both a point-radius representation (see decimalLatitude) and a footprint representation, and they may differ from each other.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/footprintSRS' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/footprintSRS',
            'description' => 'A Well-Known Text (WKT) representation of the Spatial Reference System (SRS) for the footprintWKT of the Location. Do not use this term to describe the SRS of the decimalLatitude and decimalLongitude, even if it is the same as for the footprintWKT - use the geodeticDatum instead.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/footprintSpatialFit' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/footprintSpatialFit',
            'description' => 'The ratio of the area of the footprint (footprintWKT) to the area of the true (original, or most specific) spatial representation of the Location. Legal values are 0, greater than or equal to 1, or undefined. A value of 1 is an exact match or 100% overlap. A value of 0 should be used if the given footprint does not completely contain the original representation. The footprintSpatialFit is undefined (and should be left blank) if the original representation is a point and the given georeference is not that same point. If both the original and the given georeference are the same point, the footprintSpatialFit is 1.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/georeferencedBy' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/georeferencedBy',
            'description' => 'A list (concatenated and separated) of names of people, groups, or organizations who determined the georeference (spatial representation) the Location.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/georeferencedDate' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/georeferencedDate',
            'description' => 'The date on which the Location was georeferenced. Recommended best practice is to use an encoding scheme, such as ISO 8601:2004(E).',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/georeferenceProtocol' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/georeferenceProtocol',
            'description' => 'A description or reference to the methods used to determine the spatial footprint, coordinates, and uncertainties.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/georeferenceSources' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/georeferenceSources',
            'description' => 'A list (concatenated and separated) of maps, gazetteers, or other resources used to georeference the Location, described specifically enough to allow anyone in the future to use the same resources.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/georeferenceVerificationStatus' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/georeferenceVerificationStatus',
            'description' => 'A categorical description of the extent to which the georeference has been verified to represent the best possible spatial description. Recommended best practice is to use a controlled vocabulary.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/georeferenceRemarks' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/georeferenceRemarks',
            'description' => 'Notes or comments about the spatial description determination, explaining assumptions made in addition or opposition to the those formalized in the method referred to in georeferenceProtocol.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/geologicalContextID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/geologicalContextID',
            'description' => 'An identifier for the set of information associated with a GeologicalContext (the location within a geological context, such as stratigraphy). May be a global unique identifier or an identifier specific to the data set.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/earliestEonOrLowestEonothem' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/earliestEonOrLowestEonothem',
            'description' => 'The full name of the earliest possible geochronologic eon or lowest chrono-stratigraphic eonothem or the informal name ("Precambrian") attributable to the stratigraphic horizon from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/latestEonOrHighestEonothem' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/latestEonOrHighestEonothem',
            'description' => 'The full name of the latest possible geochronologic eon or highest chrono-stratigraphic eonothem or the informal name ("Precambrian") attributable to the stratigraphic horizon from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/earliestEraOrLowestErathem' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/earliestEraOrLowestErathem',
            'description' => 'The full name of the earliest possible geochronologic era or lowest chronostratigraphic erathem attributable to the stratigraphic horizon from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/latestEraOrHighestErathem' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/latestEraOrHighestErathem',
            'description' => 'The full name of the latest possible geochronologic era or highest chronostratigraphic erathem attributable to the stratigraphic horizon from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/earliestPeriodOrLowestSystem' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/earliestPeriodOrLowestSystem',
            'description' => 'The full name of the earliest possible geochronologic period or lowest chronostratigraphic system attributable to the stratigraphic horizon from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/latestPeriodOrHighestSystem' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/latestPeriodOrHighestSystem',
            'description' => 'The full name of the latest possible geochronologic period or highest chronostratigraphic system attributable to the stratigraphic horizon from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/earliestEpochOrLowestSeries' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/earliestEpochOrLowestSeries',
            'description' => 'The full name of the earliest possible geochronologic epoch or lowest chronostratigraphic series attributable to the stratigraphic horizon from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/latestEpochOrHighestSeries' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/latestEpochOrHighestSeries',
            'description' => 'The full name of the latest possible geochronologic epoch or highest chronostratigraphic series attributable to the stratigraphic horizon from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/earliestAgeOrLowestStage' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/earliestAgeOrLowestStage',
            'description' => 'The full name of the earliest possible geochronologic age or lowest chronostratigraphic stage attributable to the stratigraphic horizon from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/latestAgeOrHighestStage' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/latestAgeOrHighestStage',
            'description' => 'The full name of the latest possible geochronologic age or highest chronostratigraphic stage attributable to the stratigraphic horizon from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/lowestBiostratigraphicZone' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/lowestBiostratigraphicZone',
            'description' => 'The full name of the lowest possible geological biostratigraphic zone of the stratigraphic horizon from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/highestBiostratigraphicZone' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/highestBiostratigraphicZone',
            'description' => 'The full name of the highest possible geological biostratigraphic zone of the stratigraphic horizon from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/lithostratigraphicTerms' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/lithostratigraphicTerms',
            'description' => 'The combination of all litho-stratigraphic names for the rock from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/group' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/group',
            'description' => 'The full name of the lithostratigraphic group from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/formation' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/formation',
            'description' => 'The full name of the lithostratigraphic formation from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/member' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/member',
            'description' => 'The full name of the lithostratigraphic member from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/bed' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/bed',
            'description' => 'The full name of the lithostratigraphic bed from which the cataloged item was collected.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/identificationID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/identificationID',
            'description' => 'An identifier for the Identification (the body of information associated with the assignment of a scientific name). May be a global unique identifier or an identifier specific to the data set.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/identifiedBy' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/identifiedBy',
            'description' => 'A list (concatenated and separated) of names of people, groups, or organizations who assigned the Taxon to the subject.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/dateIdentified' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/dateIdentified',
            'description' => 'The date on which the subject was identified as representing the Taxon. Recommended best practice is to use an encoding scheme, such as ISO 8601:2004(E).',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/identificationReferences' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/identificationReferences',
            'description' => 'A list (concatenated and separated) of references (publication, global unique identifier, URI) used in the Identification.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/identificationRemarks' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/identificationRemarks',
            'description' => 'Comments or notes about the Identification.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/identificationQualifier' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/identificationQualifier',
            'description' => 'A brief phrase or a standard term ("cf.", "aff.") to express the determiner&apos;s doubts about the Identification.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/identificationVerificationStatus' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/identificationVerificationStatus',
            'description' => 'A categorical indicator of the extent to which the taxonomic identification has been verified to be correct. Recommended best practice is to use a controlled vocabulary such as that used in HISPID/ABCD.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/typeStatus' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/typeStatus',
            'description' => 'A list (concatenated and separated) of nomenclatural types (type status, typified scientific name, publication) applied to the subject.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/taxonID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/taxonID',
            'description' => 'An identifier for the set of taxon information (data associated with the Taxon class). May be a global unique identifier or an identifier specific to the data set.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/scientificNameID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/scientificNameID',
            'description' => 'An identifier for the nomenclatural (not taxonomic) details of a scientific name.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/acceptedNameUsageID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/acceptedNameUsageID',
            'description' => 'An identifier for the name usage (documented meaning of the name according to a source) of the currently valid (zoological) or accepted (botanical) taxon.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/parentNameUsageID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/parentNameUsageID',
            'description' => 'An identifier for the name usage (documented meaning of the name according to a source) of the direct, most proximate higher-rank parent taxon (in a classification) of the most specific element of the scientificName.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/originalNameUsageID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/originalNameUsageID',
            'description' => 'An identifier for the name usage (documented meaning of the name according to a source) in which the terminal element of the scientificName was originally established under the rules of the associated nomenclaturalCode.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/nameAccordingToID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/nameAccordingToID',
            'description' => 'An identifier for the source in which the specific taxon concept circumscription is defined or implied. See nameAccordingTo.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/namePublishedInID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/namePublishedInID',
            'description' => 'An identifier for the publication in which the scientificName was originally established under the rules of the associated nomenclaturalCode.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/taxonConceptID' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/taxonConceptID',
            'description' => 'An identifier for the taxonomic concept to which the record refers - not for the nomenclatural details of a taxon.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/scientificName' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/scientificName',
            'description' => 'The full scientific name, with authorship and date information if known. When forming part of an Identification, this should be the name in lowest level taxonomic rank that can be determined. This term should not contain identification qualifications, which should instead be supplied in the IdentificationQualifier term.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/acceptedNameUsage' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/acceptedNameUsage',
            'description' => 'The full name, with authorship and date information if known, of the currently valid (zoological) or accepted (botanical) taxon.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/parentNameUsage' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/parentNameUsage',
            'description' => 'The full name, with authorship and date information if known, of the direct, most proximate higher-rank parent taxon (in a classification) of the most specific element of the scientificName.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/originalNameUsage' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/originalNameUsage',
            'description' => 'The taxon name, with authorship and date information if known, as it originally appeared when first established under the rules of the associated nomenclaturalCode. The basionym (botany) or basonym (bacteriology) of the scientificName or the senior/earlier homonym for replaced names.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/nameAccordingTo' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/nameAccordingTo',
            'description' => 'The reference to the source in which the specific taxon concept circumscription is defined or implied - traditionally signified by the Latin "sensu" or "sec." (from secundum, meaning "according to"). For taxa that result from identifications, a reference to the keys, monographs, experts and other sources should be given.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/namePublishedIn' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/namePublishedIn',
            'description' => 'A reference for the publication in which the scientificName was originally established under the rules of the associated nomenclaturalCode.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/namePublishedInYear' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/namePublishedInYear',
            'description' => 'The four-digit year in which the scientificName was published.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/higherClassification' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/higherClassification',
            'description' => 'A list (concatenated and separated) of taxa names terminating at the rank immediately superior to the taxon referenced in the taxon record. Recommended best practice is to order the list starting with the highest rank and separating the names for each rank with a semi-colon (";").',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/kingdom' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/kingdom',
            'description' => 'The full scientific name of the kingdom in which the taxon is classified.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/phylum' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/phylum',
            'description' => 'The full scientific name of the phylum or division in which the taxon is classified.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/class' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/class',
            'description' => 'The full scientific name of the class in which the taxon is classified.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/order' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/order',
            'description' => 'The full scientific name of the order in which the taxon is classified.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/family' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/family',
            'description' => 'The full scientific name of the family in which the taxon is classified.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/genus' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/genus',
            'description' => 'The full scientific name of the genus in which the taxon is classified.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/subgenus' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/subgenus',
            'description' => 'The full scientific name of the subgenus in which the taxon is classified. Values should include the genus to avoid homonym confusion.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/specificEpithet' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/specificEpithet',
            'description' => 'The name of the first or species epithet of the scientificName.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/infraspecificEpithet' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/infraspecificEpithet',
            'description' => 'The name of the lowest or terminal infraspecific epithet of the scientificName, excluding any rank designation.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/taxonRank' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/taxonRank',
            'description' => 'The taxonomic rank of the most specific name in the scientificName. Recommended best practice is to use a controlled vocabulary.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/verbatimTaxonRank' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/verbatimTaxonRank',
            'description' => 'The taxonomic rank of the most specific name in the scientificName as it appears in the original record.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/scientificNameAuthorship' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/scientificNameAuthorship',
            'description' => 'The authorship information for the scientificName formatted according to the conventions of the applicable nomenclaturalCode.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/vernacularName' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/vernacularName',
            'description' => 'A common or vernacular name.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/nomenclaturalCode' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/nomenclaturalCode',
            'description' => 'The nomenclatural code (or codes in the case of an ambiregnal name) under which the scientificName is constructed. Recommended best practice is to use a controlled vocabulary.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/taxonomicStatus' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/taxonomicStatus',
            'description' => 'The status of the use of the scientificName as a label for a taxon. Requires taxonomic opinion to define the scope of a taxon. Rules of priority then are used to define the taxonomic status of the nomenclature contained in that scope, combined with the experts opinion. It must be linked to a specific taxonomic reference that defines the concept. Recommended best practice is to use a controlled vocabulary.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/nomenclaturalStatus' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/nomenclaturalStatus',
            'description' => 'The status related to the original publication of the name and its conformance to the relevant rules of nomenclature. It is based essentially on an algorithm according to the business rules of the code.  It requires no taxonomic opinion.',
            'optional_unique' => false),

        'http://rs.tdwg.org/dwc/terms/taxonRemarks' => array (
            'name' => 'http://rs.tdwg.org/dwc/terms/taxonRemarks',
            'description' => 'Comments or notes about the taxon or name.',
            'optional_unique' => false),

        'map' => array (
            'name' => 'Map',
            'description' => '(latitude, longitude)',
            'optional_unique' => false),
    );

    return $sources;
  }

  /**
   * Add custom fields to the default form
   */
  public function sourceForm($source_config){
    $form = array();
    $form['#weight'] = -10;

    $output = t('Upload your Darwin Core Arcive (DwC-A)');

    $form['help']['#markup'] = '<div class="help"><p>' . $output . '</p></div>';

    return $form;
  }

  /**
   * Parse the DwC-A file and create data data resource to store the
   * occurrence.txt information
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result){
    // Increase the memory limit
    ini_set('memory_limit', '1024M');

    // Get config and current state
    $source_config = $source->getConfigFor($this);
    $this->state = $source->state(FEEDS_PARSE);

    // library includes
    feeds_include_library('dwca.inc', 'dwca');

    $import_file_path = drupal_realpath($fetcher_result->getFilePath());

    $dwca = new DwCA($import_file_path);
    $dwca->open();

    // Determine section to parse, parse.
    $start = $this->state->pointer ? $this->state->pointer : $dwca->parser->lastLinePos();

    $limit = $source->importer->getLimit();
    print $limit;

    $rows = $dwca->get_records($start, $limit);
    // --------------------------------- //

    // Report progress.
    $this->state->total = filesize($dwca->meta->core->files[0]);
    $this->state->pointer = $dwca->parser->lastLinePos();
    $progress = $dwca->parser->lastLinePos()? $dwca->parser->lastLinePos() : $this->state->total;
    $this->state->progress($this->state->total, $progress);

    // Create a result object and return it.
    return new FeedsParserResult($rows, $source->feed_nid);
  }
}

