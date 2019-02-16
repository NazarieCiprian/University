package com.example.ciprian.exam

import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.support.design.widget.Snackbar
import android.support.v7.widget.LinearLayoutManager
import android.support.v7.widget.RecyclerView
import android.view.View
import com.example.ciprian.exam.adapters.MainAdapter
import com.example.ciprian.exam.adapters.ThirdAdapter
import kotlinx.android.synthetic.main.activity_first.*
import kotlinx.android.synthetic.main.activity_fourth.*

class FourthActivity : AppCompatActivity(),MyCallback {
    var adapter: ThirdAdapter? = null
    lateinit var name:String
    private var recyclerView: View? = null
    private var manager: Manager? = null
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_fourth)
        name = intent.extras!!.getSerializable("name")!!.toString()
        manager = Manager(application as MyApp)
        recyclerView = findViewById(R.id.receiver_list)
        setupRecyclerView(recyclerView as RecyclerView)
        loadEvents()
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        loadEvents()
    }

    fun loadEvents():Boolean{
        progressFourth.visibility = View.VISIBLE
        val connectivity = manager!!.networkConnectivity(applicationContext)
        if(!connectivity){
            showError("There is no connection")
        } else{
            manager!!.loadReceiver(name,progressFourth,this,this)
        }

        return connectivity
    }
    override fun clear() {

    }

    override fun showError(message: String) {
        progressFourth.visibility = View.GONE
        Snackbar.make(recyclerView!!, message, Snackbar.LENGTH_INDEFINITE)
                .setAction("RETRY") { loadEvents() }.show()
    }

    private fun setupRecyclerView(recyclerView: RecyclerView){
        adapter = ThirdAdapter()

        recyclerView.layoutManager = LinearLayoutManager(this)
        recyclerView.adapter = adapter
    }
}
