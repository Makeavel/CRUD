package com.api.crud.controller;

import java.util.List;

import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.api.crud.model.Usuario;
import com.api.crud.service.UsuarioService;

@RestController
@RequestMapping("/api")
public class UsuarioController{

    
    private final UsuarioService usuarioService;

    public UsuarioController(UsuarioService usuarioService){
        this.usuarioService = usuarioService;
    }

    @PostMapping("/create")
    public Usuario getCreate(@RequestBody Usuario user){
        return usuarioService.findPostCreate(user);
    }

    @GetMapping("/read")
    public List<Usuario> getReadAll(){
        return usuarioService.findGetReadAll();
    }
    
    @PutMapping("/update")
    public Usuario getUpdate(@RequestBody Usuario user){
        return usuarioService.findPutUser(user);
    }
    
    @DeleteMapping("/delete/{cpf}")
    public Usuario getDelete(@PathVariable("cpf")String cpf){
        return usuarioService.findDeleteUser(cpf);
    }

}
