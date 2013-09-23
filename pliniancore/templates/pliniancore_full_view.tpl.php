
<div class="pliniancore-full-view">

  <div class="pliniancore-title">
      <?php
        foreach($node->field_taxonomic_name as $language){
          foreach($language as $term){
            $full_term = taxonomy_term_load($term['tid']);
            print l(t($full_term->name), 'taxonomy/term/'.$full_term->tid );
          }
        }
      ?>
  </div>
  <div class="pliniancore-species-record">
    <?php if(!empty($node->institution_code)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Institution Code'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->institution_code; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->date_last_modified)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Date Last Modified'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->date_last_modified; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->taxon_record_id)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Taxon Record ID'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->taxon_record_id; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->taxon_record_language)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Language'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->taxon_record_language; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->creators)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Creators'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->creators; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->distribution)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Distribution'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->distribution; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->abstract)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Abstract'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->abstract; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->kingdom)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Kingdom'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->kingdom; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->phylum)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Phylum'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->phylum; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->class)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Class'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->class; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->order)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Order'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->order; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->family)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Family'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->family; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->genus)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Genus'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->genus; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->synonyms)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Synonyms'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->synonyms; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->author_year_of_scientific_name)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Scientific Name Autorship'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->author_year_of_scientific_name; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->species_publication_reference)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Species Publication Reference'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->species_publication_reference; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->common_names)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Common Names'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->common_names; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->typification)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Typification'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->typification; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->global_unique_identifier)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Global Unique Identifier'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->global_unique_identifier; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->contributors)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Contributors'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->contributors; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->date_created)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Date Created'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->date_created; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->habit)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Habit'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->habit; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->life_cycle)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Life Cycle'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->life_cycle; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->reproduction)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Reproduction'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->reproduction; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->annual_cycle)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Annual Cycle'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->annual_cycle; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->scientific_description)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Scientific Description'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->scientific_description; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->brief_description)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Brief Description'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->brief_description; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->feeding)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Feeding'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->feeding; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->behavior)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Behavior'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->behavior; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->interactions)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Interactions'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->interactions; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->chromosomic_number_n)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Chromosomic Number N'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->chromosomic_number_n; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->molecular_data)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Molecular Data'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->molecular_data; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->population_biology)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Population Biology'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->population_biology; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->threat_status)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Threat Status'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->threat_status; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->legislation)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Legislation'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->legislation; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->habitat)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Habitat'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->habitat; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->territory)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Territory'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->territory; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->endemicity)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Endemicity'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->endemicity; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->uses)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Uses'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->uses; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->management)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Management'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->management; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->folklore)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Folklore'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->folklore; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->references)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('References'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->references; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->unstructured_documentation)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Unstructured Documentation'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->unstructured_documentation; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->other_information_sources)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Other Information Sources'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->other_information_sources; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->papers)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Papers'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->papers; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->identification_keys)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Identification Keys'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->identification_keys; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->migratory_data)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Migratory Data'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->migratory_data; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->ecological_significance)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Ecological Significance'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->ecological_significance; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->unstructured_natural_history)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Unstructured Natural History'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->unstructured_natural_history; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->invasiveness_data)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Invasiveness Data'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->invasiveness_data; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->target_audiences)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Target Audiences'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->target_audiences; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if(!empty($node->version)): ?>
      <div class="pliniancore-field">
        <div class="pliniancore-field-title">
          <?php print t('Version'); ?>
        </div>
        <div class="pliniancore-field-content">
          <?php print $node->version; ?>
        </div>
      </div>
    <?php endif; ?>

  </div>
</div>


