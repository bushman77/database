var content = [text("Hello World!")];
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


function accordianMenu(){
  // GET ALL SHOPPING LIST ITEMS
  var content = [text("hello world")];
  $.ajax({
     type: 'POST',
      url: "/test/api.php",
     data: { request: {action: "query", table: "shoppinglist", target: "*", order_by: "commonname", dir: "ASC"}},
  success: function(data){ window['content'] = JSON.parse(data) },
  async:false
  }
);
    
  var list = [];
  var sortedObjs = window['content'].result;
  sortedObjs.forEach(
    element => 
      list.push(
        div(
          [ clas("media"),
            attr("onClick", "selectItem("+JSON.stringify(element)+")")
          ],
          [ img(
              [ clas("mr-3"),
                attr("src","/test/images/"+element.store+".webp"),
                attr("alt", element.store),
                attr("width", "50"),
                attr("height", "60")
              ]
            ),
            div(
              [clas("media-body")],
              [ h5(
                  [clas("mt-0")],
                  [ text(element.commonname),
                    div(
                      [],
                      [ span([],[text("$"+element.cost)])
                      ]
                    )
                  ]
                )
              ]
            )
          ]
        )
      )
  )
  
  return div( [ clas("accordian")],
              [ accordianMenuItem("One", "ShoppingList",
                  div([ clas("card")
                      ],
                      list)
                )
              ]
            )
}

/*
  GROUPED TOGETHER ELEMENTS TO MAKE A LARGER MORE COMPLEX ITEM
*/

function accordianMenuItem(id, buttontext, content){
  return  div( [ clas("card")],
               [ div( [clas("card-header"),
                       {attribute: "id", value: "heading"+id}
                      ],
                      [ h5( [clas("mb-0")],
                            [button( [ clas("mb-0 btn btn-link collapsed"),
                                       {attribute: "data-toggle", value: "collapse"},
                                       {attribute: "data-target", value: "#collapse"+id},
                                       {attribute: "aria-expanded", value: "false"},
                                       {attribute: "aria-controls", value: "collapse"+id}
                                     ],
                                     [text(buttontext)]
                                   )
                            ]
                          )
                      ]
                    ),
                 div( [ {attribute: "id", value: "collapse"+id},
                        clas("collapse"),
                        {attribute: "aria-labelledby", value: "heading"+id},
                        {attribute: "data-parent", value: "#accordion"}
                      ],
                      [ div([ clas("card-body"),
                              attr("style", "overflow-y: scroll; height: 80vh;"),
                            ],
                            [
                         div(
                           [ attr("id","shoppingListTotal"),
                             clas("total"),
                             attr("style", 
                               "position: absolute;"+
                               "top:5px;"+
                               "right:10px;"+
                               "border: black solid 1px;"+
                               "height:50px;"+
                               "width:100px;"+
                               "border-radius: 15px;"+
                               "text-align: center;"+
                               "vertical-align: middle;"+
                               "color: green;"
                             )
                           ],
                           [ div([],[text("TOTAL")]),
                             div([attr("style","font-size: small;")],[10000])
                           ]
                         ),
                         content]
                           )
                      ]
                    )
               ]
             )
}

function modalLoginRegisterForm(){
  return div(
                       [clas("modal-c-tabs")],
                       [ ul(
                           [ clas("nav nav-tabs md-tabs tabs-2 light-blue darken-3"),
                             attr("role", "tablist")
                           ],
                           [ li(
                               [ clas("nav-item")
                               ],
                               [ a(
                                   [ clas("nav-link active"),
                                     attr("data-toggle","tab"),
                                     attr("href", "#panel7"),
                                     attr("role", "tab")
                                   ],
                                   [ i(
                                       [clas("fas fa-user mr-1")],
                                       [text("Login")]
                                     )
                                   ]
                                 )
                               ]
                             ),
                             li(
                               [ clas("nav-item")
                               ],
                               [ a(
                                   [ clas("nav-link"),
                                     attr("data-toggle","tab"),
                                     attr("href", "#panel8"),
                                     attr("role", "tab")
                                   ],
                                   [ i(
                                       [clas("fas fa-user mr-1")],
                                       [text("Register")]
                                     )
                                   ]
                                 )
                               ]
                             )
                           ]
                         ),
                       div(
                         [ clas("tab-content")
                         ],
                         
                         [ ////////PANEL7/////////////////////////////////////////
                           div( 
                             [ clas("tab-pane fade in active show"),
                               attr("id", "panel7"),
                               attr("role", "tabpanel")
                             ],
                             [ div(
                                 [clas("modal-body mb-1")
                                 ],
                                 [ div(
                                     [clas("md-form form-sm mb-5")
                                     ],
                                     [ i([clas("fas fa-envelope prefix")],[]),
                                       label(
                                         [ clas("loginEmailLabel"),
                                           attr("data-error", "wrong"),
                                           attr("data-success", "right"),
                                           attr("for", "ModalRInput10")
                                         ],
                                         [text("Email")]
                                       ),
                                       input(
                                         [ clas("loginEmail form-control form-control-sm validate"),
                                           attr("id", "modalLRInput10"),
                                           attr("type", "email")
                                         ]
                                       )
                                     ]
                                   ),
                                   div(
                                     [clas("md-form form-sm mb-4")],
                                     [i([clas("fas fa-lock prefix")],[]),
                                       label(
                                         [ clas("loginPasswordLabel"),
                                           attr("data-error", "wrong"),
                                           attr("data-success", "right"),
                                           attr("for", "ModalRInput11")
                                         ],
                                         [text("Password")]
                                       ),
                                       input(
                                         [ clas("loginPassword form-control form-control-sm validate"),
                                           attr("id", "modalLRInput11"),
                                           attr("type", "password")
                                         ]
                                       )
                                     ]
                                   ),
                                   div(
                                     [clas("modal-footer")],
                                     [div(
                                        [clas("options text-center text-md-right mt-1")],
                                        [ p(
                                             [],
                                             [ text("Forgot "),
                                               a(
                                                 [ clas("blue-text"),
                                                   attr("href", "#")
                                                 ],
                                                 [text("Password?")]
                                               )
                                             ]
                                           )
                                        ]
                                      ),
                                      button(
                                        [ clas("btn btn-outline-info waves-effect ml-auto"),
                                          attr("id", "login"),
                                          attr("type", "button"),
                                          attr("onClick", "logIn();")
                                        ],
                                        [text("Login")]
                                      )
                                     ]
                                   )
                                 ]
                               )
                             ]
                           ),
                           ////////PANEL8////////////////////////////////////
                           div(
                             [ clas("tab-pane fade"),
                               attr("id", "panel8"),
                               attr("role", "tabpanel")
                             ],
                             [ div(
                                 [clas("modal-body mb-1")
                                 ],
                                 [ div(
                                     [clas("md-form form-sm mb-5")
                                     ],
                                     [ i([clas("fas fa-envelope prefix")],[]),
                                       label(
                                         [ clas("registerEmailLabel"),
                                           attr("data-error", "wrong"),
                                           attr("data-success", "right"),
                                           attr("for", "ModalRInput12")
                                         ],
                                         [text("Email")]
                                       ),
                                       input(
                                         [ clas("registerEmail form-control form-control-sm validate"),
                                           attr("id", "modalLRInput12"),
                                           attr("type", "email")
                                         ]
                                       )
                                     ]
                                   ),
                                   div(
                                     [clas("md-form form-sm mb-4")],
                                     [i([clas("fas fa-lock prefix")],[]),
                                       label(
                                         [ clas("registerPasswordLabel"),
                                           attr("data-error", "wrong"),
                                           attr("data-success", "right"),
                                           attr("for", "ModalRInput13")
                                         ],
                                         [text("Password")]
                                       ),
                                       input(
                                         [ clas("registerEmail form-control form-control-sm validate"),
                                           attr("id", "modalLRInput13"),
                                           attr("type", "password")
                                         ]
                                       )
                                     ]
                                   ),div(
                                     [clas("md-form form-sm mb-4")],
                                     [i([clas("fas fa-lock prefix")],[]),
                                       label(
                                         [ clas("registerPasswordCheckLabel"),
                                           attr("data-error", "wrong"),
                                           attr("data-success", "right"),
                                           attr("for", "ModalRInput14")
                                         ],
                                         [text("Password")]
                                       ),
                                       input(
                                         [ clas("registerPasswordCheck form-control form-control-sm validate"),
                                           attr("id", "modalLRInput14"),
                                           attr("type", "password")
                                         ]
                                       )
                                     ]
                                   ),
                                   div(
                                     [clas("modal-footer")],
                                     [div(
                                        [clas("options text-center text-md-right mt-1")],
                                        [ p(
                                             [],
                                             [ text("Forgot "),
                                               a(
                                                 [ clas("blue-text"),
                                                   attr("href", "#")
                                                 ],
                                                 [text("Password?")]
                                               )
                                             ]
                                           )
                                        ]
                                      ),
                                      button(
                                        [ clas("btn btn-outline-info waves-effect ml-auto"),
                                          attr("id", "register"),
                                          attr("type", "button"),
                                          attr("onCick", "registerAccount();")
                                        ],
                                        [text("Login")]
                                      )
                                     ]
                                   )
                                 ]
                               )
                             ]
                           )
                         ]
                       )
                       ]
                     )
}

function displayItem(item){
  console.log(item)
  $(".modal-content")
    .html( form(
             [attr("stye","padding:5px;")],
             [ div(
                 [clas("form-group")],
                 [ label(
                     [attr("for", "exampleInputEmail1")],
                     [text("Email address")]
                   ),
                   input(
                     [attr("type","email"),
                      clas("form-control"),
                      attr("id","exampleInputEmail1"),
                      attr("aria-describedby", "emailHelp"),
                      attr("placeholder","Enter email"),
                      attr("value", item.commonname)
                     ]
                   ),
                   small(
                     [ attr("id", "emailHelp"),
                       clas("form-text text-muted")
                     ],
                     [text("We'll never share your email with anyone else.")]
                   )
                 ]
               ),
               div(
                 [clas("form-group")],
                 [ label(
                     [attr("for", "exampleInputPassword1")],
                     [text("Password")]
                   ),
                   input(
                     [attr("type", "password"),
                      clas("form-control"),
                      attr("id", "exampleInputPassword1"),
                      attr("placeholder" ,"Password")
                     ]
                   ),
                   button(
                     [attr("type","submit"),
                      clas("btn btn-primary")
                     ],
                     [text("Submit")]
                   )
                 ]
               )
             ]
           )
         )
  $(".modal").modal("show")
}

/*
  commonname: "9-Grain Ciabatta Buns"
cost: "5.49"
id: "220"
item: "9-Grain Ciabatta Buns"
quantity: "1"
restock: "0"
selected: "0"
store: "Costco"
unit: "Pack"
*/
function selectItem(id){
  alert(id.id)
}
