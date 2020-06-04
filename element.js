/*
  HTML ATTRIBUTE PROPERY FUNCTIONS
*/

function attr(t, v){
  return {attribute: t, value: v}
}

function clas(v){
  return {attribute: "class", value: v}
}


function id(v){
  return {attribute: "id", value: v}
}

/*
  BASIC HTML OBJECTS
*/
function button(attributes, content){
  element = document.createElement("button")
  var i;
  var ci;
  for(i=0; i<attributes.length;i++){
    $(element).attr(attributes[i].attribute, attributes[i].value)
  }
  for(ci=0;ci<content.length;ci++){
    $(element).append(content[ci])
  }
  return $(element)
}

function a(attributes, content) {
    var element = document.createElement("a")
    var i;
    var ci;
    for ( i =0; i<attributes.length; i++ ) {
      $(element).attr(attributes[i].attribute, attributes[i].value)
    }
    for (ci=0; ci<content.length; ci++) {
      $(element).append(content[ci])
    }
  return $(element)
}

function div(attributes, content) {
    var element = document.createElement("div")
    var i;
    var ci;
    for ( i =0; i<attributes.length; i++ ) {
      $(element).attr(attributes[i].attribute, attributes[i].value)
    }
    for (ci=0; ci<content.length; ci++) {
      $(element).append(content[ci])
    }
  return $(element)
}

function form(attributes, content) {
    var element = document.createElement("form")
    var i;
    var ci;
    for ( i =0; i<attributes.length; i++ ) {
      $(element).attr(attributes[i].attribute, attributes[i].value)
    }
    for (ci=0; ci<content.length; ci++) {
      $(element).append(content[ci])
    }
  return $(element)
}



function i(attributes, content) {
    var element = document.createElement("div")
    var i;
    var ci;
    for ( i =0; i<attributes.length; i++ ) {
      $(element).attr(attributes[i].attribute, attributes[i].value)
    }
    for (ci=0; ci<content.length; ci++) {
      $(element).append(content[ci])
    }
  return $(element)
}

function img(attributes) {
    var element = document.createElement("img")
    var i;
    
    for ( i =0; i<attributes.length; i++ ) {
      $(element).attr(attributes[i].attribute, attributes[i].value)
    }
    
  return $(element)
}

function input(attributes) {
    var element = document.createElement("input")
    var i;
    
    for ( i =0; i<attributes.length; i++ ) {
      $(element).attr(attributes[i].attribute, attributes[i].value)
    }
    
  return $(element)
}

function label(attributes, content) {
    var element = document.createElement("label")
    var i;
    var ci;
    for ( i =0; i<attributes.length; i++ ) {
      $(element).attr(attributes[i].attribute, attributes[i].value)
    }
    for (ci=0; ci<content.length; ci++) {
      $(element).append(content[ci])
    }
  return $(element)
}

function p(attributes, content) {
    var element = document.createElement("p")
    var i;
    var ci;
    for ( i =0; i<attributes.length; i++ ) {
      $(element).attr(attributes[i].attribute, attributes[i].value)
    }
    for (ci=0; ci<content.length; ci++) {
      $(element).append(content[ci])
    }
  return $(element)
}



function ul(attributes, content) {
    var element = document.createElement("ul")
    var i;
    var ci;
    for ( i =0; i<attributes.length; i++ ) {
      $(element).attr(attributes[i].attribute, attributes[i].value)
    }
    for (ci=0; ci<content.length; ci++) {
      $(element).append(content[ci])
    }
  return $(element)
}

function li(attributes, content) {
    var element = document.createElement("li")
    var i;
    var ci;
    for ( i =0; i<attributes.length; i++ ) {
      $(element).attr(attributes[i].attribute, attributes[i].value)
    }
    for (ci=0; ci<content.length; ci++) {
      $(element).append(content[ci])
    }
  return $(element)
}

function nav(attributes, content) {
    var element = document.createElement("nav")
    var i;
    var ci;
    for ( i =0; i<attributes.length; i++ ) {
      $(element).attr(attributes[i].attribute, attributes[i].value)
    }
    for (ci=0; ci<content.length; ci++) {
      $(element).append(content[ci])
    }
  return $(element)
}

function small(attributes, content) {
    var element = document.createElement("small")
    var i;
    var ci;
    for ( i =0; i<attributes.length; i++ ) {
      $(element).attr(attributes[i].attribute, attributes[i].value)
    }
    for (ci=0; ci<content.length; ci++) {
      $(element).append(content[ci])
    }
  return $(element)
}

function span(attributes, content) {
    var element = document.createElement("span")
    var i;
    var ci;
    for ( i =0; i<attributes.length; i++ ) {
      $(element).attr(attributes[i].attribute, attributes[i].value)
    }
    for (ci=0; ci<content.length; ci++) {
      $(element).append(content[ci])
    }
  return $(element)
}

function text(string) {
  return string
}

function h5(attributes, content) {
  var element = document.createElement("h5")
  var i;
  var ci;
  for(i=0; i<attributes.length;i++){
    $(element).attr(attributes[i].attribute, attributes[i].value)
  }
  for(ci=0;ci<content.length;ci++){
    $(element).append(content[ci])
  }
  return $(element)
}
