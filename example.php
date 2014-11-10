<ul>
<?php

  /*
  * Generate URL according with termID
  */
  function generateLink($term){
    
    global $base_path;

    $term_uri = taxonomy_term_uri($term); // get array with path
    $term_path = $term_uri['path'];
    $contar = explode("/", drupal_get_path_alias($term_path));
    for($x=0;$x<count($contar);$x++){
      $retorno = $contar[$x];
    }
    
    $link = "<a href='" . $base_path . 'ciencia/area/' . $retorno . "' title='".$term->name."'>" . $term->name . "</a>";
    return $link;
  }

  $taxonomyName = 'categorias_de_olho_na_ciencia';
  $vocabulary = taxonomy_vocabulary_machine_name_load($taxonomyName);
  $tree = taxonomy_get_tree($vocabulary->vid);

  foreach ($tree as $term) {
    if($term->parents[0] == 0){
      echo '<li class="pai pai-'.$term->tid.'">';

      echo generateLink($term);

      // Detect children of term
      $children = taxonomy_get_children($term->tid);
      // Browsing the children
      echo '<ul class="children">';
      foreach ($children as $f) {
        echo '<li>'. generateLink($f) . '</li>';
      }
      echo "</ul>";
      echo '</li>';
    }
  }

?>
</ul>