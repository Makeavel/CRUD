package com.api.crud.controller;

@RestController
@RequestMapping("/api")
public class UsuarioController{

    @Autowired
    private UsuarioService usuarioService;

    @GetMapping("/create/{nome}")
    public Usuario getCreate(@PathVariable("nome")String nome){
        return usuarioService.findGetCreate(nome);
    }

    


}