<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Produto;

class ProdutosController extends Controller
{
    
    public function create(){
        return view('create');
    }

    public function store(Request $request){

        Produto::create([
            'nome' => $request->nome,
            'custo' => $request->custo,
            'preco' => $request->preco,
            'quantidade'=> $request->quantidade,
        ]);

        return "Produto criado com sucesso";
    }

    public function show($id){
        $produto = Produto::findOrFail($id);
        return view('show', ['produto' => $produto]);
    }

    public function edit($id){
        $produto = Produto::findOrFail($id);
        return view('edit', ['produto' => $produto]);
    }

    public function update(Request $request , $id){

        $produto = Produto::findOrFail($id);

        $produto-> update([
            'nome' => $request->nome,
            'custo' => $request->custo,
            'preco' => $request->preco,
            'quantidade'=> $request->quantidade,
        ]);

        return "Produto atualizado";
    }

    public function delete($id){
        $produto = Produto::findOrFail($id);
        return view('delete', ['produto' => $produto]);
    }

    public function destroy($id){

        $produto = Produto::findOrFail($id);
        $produto-> delete();

        return "deletado com sucesso";
    }
}
