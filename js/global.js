// @adonaidiofanes

(function ($) {

	$(function() {
	
		$('.tmwc-menu > ul > li > a').click(function() {
		  $('.tmwc-menu li').removeClass('active');
		  $(this).closest('li').addClass('active');	
		  var checkElement = $(this).next();
		  if((checkElement.is('ul')) && (checkElement.is(':visible'))) {
		    $(this).closest('li').removeClass('active');
		    checkElement.slideUp('normal');
		  }
		  if((checkElement.is('ul')) && (!checkElement.is(':visible'))) {
		    $('.tmwc-menu ul ul:visible').slideUp('normal');
		    checkElement.slideDown('normal');
		  }
		  if($(this).closest('li').find('ul').children().length == 0) {
		    return true;
		  } else {
		    return false;	
		  }		
		});
	
	}) // fim da funcao jquery

})(jQuery);
