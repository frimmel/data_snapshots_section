Permalink
=========

This is a jQuery plugin that converts a DOM element into "permalink"
widget.  This makes the element clickable, and clicking on it will pop
up a small div containing a URL that has been pre-selected, so that
the user can conveniently copy/paste the URL.  The URL is passed as an
option to the plugin.

For example, if you have

```html
<span id="permalink">Permalink</span>
```

in your document, then invoking

```js
$('#permalink').permalink({
    url : 'http://www.mysite.com/page.html'
});
```

will cause the above `span` to appear as

<p align="center">
  <img src="./sample.png?raw=true"/>
</p>

and when the user clicks on it the following will appear:

<p align="center">
  <img src="./sample-clicked.png?raw=true"/>
</p>

The intended use is in stateful browser applications which can generate URLs
to re-create the current state; the permalink widget provides a convenient
way for the application to give the user access to the URL, without always
displaying it somewhere on the page.

Note that the use of the word "Permalink" in the targeted element is
optional; the plugin simply prepends a little link icon to the front
of the element's existing content, and makes the element clickable.
So you can use whatever text (or image) you want.  You can also suppress the
insertion of the link icon by specifying the `icon : false` option when
invoking the plugin:

```js
$('#permalink').permalink({
    url  : 'http://www.mysite.com/page.html',
    icon : false
});
```

Permalink provides a single plugin method named `url`, which can be used to
set or get the current url after the plugin has been invoked:

```js
// set the widget's url to http://www.newsite.com/page.html:
$('#permalink').permalink('url', 'http://www.newsite.com/page.html');
```

```js
// return the widget's current url:
$('#permalink').permalink('url');
```

Installation
------------

To install the permalink plugin, just put this directory somewhere on the same
server as your application, and load the `permalink.js` and `permalink.css` files
in the `head` of your page.  Obviously, you'll need to load jQuery itself as well,
before loading `permalink.js`.  For example, if you put the Permalink files
in a directory named `permalink`, which is in the same directory as your HTML
file, then your HTML file should look something like this:

```html
<html>
  <head>
    <script src="http://code.jquery.com/jquery-1.11.0.min.js"></script>
    <script type="text/javascript" src="permalink/permalink.js"></script>
    <link type="text/css" rel="stylesheet" href="permalink/permalink.css"/>
  <head>
  <body>
    ...
  </body>
</html>
```

The files that Permalink needs at run time are `permalink.js`,
`permalink.css`, `link.png`, and `closebutton.png`, so you can delete
the other files from this directory if you don't want them.  The files
`permalink.css`,`link.png`, and `closebutton.png` should all be in the
same directory, but `permalink.js` can be located elsewhere if you
want.
